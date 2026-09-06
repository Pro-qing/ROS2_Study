#include <chrono>
#include <cstddef>
#include <memory>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>("lesson02_timer");
  [[maybe_unused]] std::size_t count = 0;

  auto timer = node->create_wall_timer(
    1s,
    [&]() {
      // TODO: 输出当前 count，然后将 count 加一。
    });

  (void)timer;
  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}
