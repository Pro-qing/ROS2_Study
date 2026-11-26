#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_srvs/srv/set_bool.hpp"

int main(int argc, char * argv[])
{
  using Service = std_srvs::srv::SetBool;

  rclcpp::init(argc, argv);
  auto node = std::make_shared<rclcpp::Node>("lesson07_service_server");
  const auto logger = node->get_logger();

  // TODO: replace the placeholder response with the service contract.
  auto service = node->create_service<Service>(
    "/lesson07_set_enabled",
    [logger](
      const std::shared_ptr<Service::Request> request,
      std::shared_ptr<Service::Response> response) {
      (void)request;
      response->success = false;
      response->message = "TODO: implement request handling";
      RCLCPP_INFO(logger, "service request received");
    });

  RCLCPP_INFO(logger, "service server is ready.");
  (void)service;
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
