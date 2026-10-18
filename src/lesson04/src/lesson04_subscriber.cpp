#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("lesson04_subscriber");
  const auto logger = node->get_logger();

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription;
  // TODO 1: 使用 create_subscription<std_msgs::msg::String> 创建订阅。
  // 话题 /lesson03_chatter，QoS 为 KeepLast(10)、reliable、volatile。
  // 将返回的智能指针赋给 subscription，并在下面的回调中处理消息。
    // TODO 2: 回调按值捕获 logger，参数使用 String::ConstSharedPtr。
  // 用 RCLCPP_INFO 输出 received: <消息 data>；不要自行生成计数。
  auto qos = rclcpp::QoS(rclcpp::KeepLast(10)).reliable().durability_volatile();
  subscription = node->create_subscription<std_msgs::msg::String>(
    "/lesson03_chatter",
    qos,
    [logger](std_msgs::msg::String::ConstSharedPtr msg) {
      RCLCPP_INFO(logger, "received: %s", msg->data.c_str());
    }
  );

  RCLCPP_INFO(logger, "subscriber is ready to receive messages.");

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
