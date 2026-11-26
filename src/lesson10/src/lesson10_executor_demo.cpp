#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("lesson10_executor_demo");
  const auto logger = node->get_logger();

  // TODO 1: keep both callbacks observable and explain their scheduling.
  auto timer = node->create_wall_timer(
    1s,
    [logger]() {
      RCLCPP_INFO(logger, "timer callback");
    });
  auto subscription = node->create_subscription<std_msgs::msg::String>(
    "/lesson10_input",
    rclcpp::QoS(10),
    [logger](std_msgs::msg::String::ConstSharedPtr message) {
      RCLCPP_INFO(logger, "subscription callback: %s", message->data.c_str());
    });

  // TODO 2: compare this executor with the executor choices discussed in the lesson.
  rclcpp::executors::SingleThreadedExecutor executor;
  executor.add_node(node);
  (void)timer;
  (void)subscription;
  executor.spin();

  rclcpp::shutdown();
  return 0;
}
