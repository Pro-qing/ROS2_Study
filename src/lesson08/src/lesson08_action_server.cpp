#include <memory>

#include "example_interfaces/action/fibonacci.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

int main(int argc, char * argv[])
{
  using Action = example_interfaces::action::Fibonacci;
  using GoalHandle = rclcpp_action::ServerGoalHandle<Action>;

  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("lesson08_action_server");

  // TODO 1: accept valid goals and reject invalid goal requests.
  auto action_server = rclcpp_action::create_server<Action>(
    node,
    "lesson08_fibonacci",
    [](const rclcpp_action::GoalUUID &, std::shared_ptr<const Action::Goal>) {
      return rclcpp_action::GoalResponse::REJECT;
    },
    [](const std::shared_ptr<GoalHandle>) {
      return rclcpp_action::CancelResponse::REJECT;
    },
    [](const std::shared_ptr<GoalHandle>) {
      // TODO 2: start goal execution and publish feedback/result.
    });

  RCLCPP_INFO(node->get_logger(), "action server skeleton is ready.");
  (void)action_server;
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
