#include <memory>

#include "example_interfaces/action/fibonacci.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

int main(int argc, char * argv[])
{
  using Action = example_interfaces::action::Fibonacci;

  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("lesson08_action_client");
  auto client = rclcpp_action::create_client<Action>(node, "lesson08_fibonacci");

  // TODO 1: wait for the action server with a bounded timeout.
  // TODO 2: fill a Goal and configure goal, feedback, and result callbacks.
  RCLCPP_INFO(node->get_logger(), "action client skeleton is ready.");
  (void)client;

  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
