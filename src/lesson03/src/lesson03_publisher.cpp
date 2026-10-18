#include <chrono>
#include <cstddef>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>("lesson03_publisher");
  auto publisher = node->create_publisher<std_msgs::msg::String>(
    "/lesson03_chatter",
    rclcpp::QoS(rclcpp::KeepLast(10)).reliable().durability_volatile());
  std::size_t count = 0;

  auto timer = node->create_wall_timer(
    1s,
    [publisher, &count]() {
      auto message = std_msgs::msg::String();
      message.data = "count = " + std::to_string(count);
      publisher->publish(message);
      count++;
    });
  
  RCLCPP_INFO(node->get_logger(), "publisher is ready to send messages.");

  (void)timer;
  rclcpp::spin(node);

  rclcpp::shutdown();
  return 0;
}
