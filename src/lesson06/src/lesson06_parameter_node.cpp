#include <chrono>
#include <cstddef>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("lesson06_parameter_node");
  const auto logger = node->get_logger();

  // TODO 1: choose and document the parameter names and defaults.
  // TODO 1: 选择并记录参数名称和默认值。
  // 声明并获取参数 （本例仅在启动时读取一次，运行时修改不会修改）
  const auto prefix = node->declare_parameter<std::string>("message_prefix", "count = ");
  int64_t period_ms = node->declare_parameter<int64_t>("period_ms", 1000);

  if (period_ms <= 0) {
    RCLCPP_WARN(logger, "period_ms = %ld is valid, fallback to 1000 ms",
        static_cast<long>(period_ms));
    period_ms = 1000;
  }

  // TODO 2: retrieve the declared parameters with their intended types.
  std::size_t count = 0;
  auto timer = node->create_wall_timer(
    std::chrono::milliseconds(period_ms),
    [logger, prefix, &count]() {
      RCLCPP_INFO(logger, "%s%zu", prefix.c_str(), count);
      ++count;
    });
  (void)timer;  // 保持 timer 存活，否则回调不会被触发

  RCLCPP_INFO(logger, "parameter node is ready (period=%ld ms).",
              static_cast<long>(period_ms));
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
