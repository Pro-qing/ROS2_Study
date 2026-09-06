#include <memory>

#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto node = std::make_shared<rclcpp::Node>("lesson01_logger");

  // TODO: 使用 RCLCPP_INFO 输出一条介绍自己的消息。
  // 例如：消息中可以包含你的名字、学习目标或今天的日期。
  RCLCPP_INFO(node->get_logger(), "Hello, I am Promise. My learning goal is to master ROS2 logging. Today's date is 8.29.");

  rclcpp::shutdown();
  return 0;
}
