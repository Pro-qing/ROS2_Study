#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/set_bool.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  using Service = std_srvs::srv::SetBool;

  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("lesson07_service_client");
  auto client = node->create_client<Service>("/lesson07_set_enabled");

  // TODO 1: handle the unavailable-service case without an unbounded wait.
  if (!client->wait_for_service(2s)) {
    RCLCPP_ERROR(node->get_logger(), "service is not available");
    rclcpp::shutdown();
    return 1;
  }

  auto request = std::make_shared<Service::Request>();
  // TODO 2: choose the request value and inspect the response.
  request->data = true;
  auto future = client->async_send_request(request);
  const auto result = rclcpp::spin_until_future_complete(node, future, 2s);
  if (result == rclcpp::FutureReturnCode::SUCCESS) {
    RCLCPP_INFO(node->get_logger(), "response received");
  } else {
    RCLCPP_ERROR(node->get_logger(), "request did not complete");
  }

  rclcpp::shutdown();
  return result == rclcpp::FutureReturnCode::SUCCESS ? 0 : 1;
}
