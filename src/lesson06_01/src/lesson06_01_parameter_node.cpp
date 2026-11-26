#include <chrono>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rclcpp/rclcpp.hpp"

using namespace std::chrono_literals;

class ParameterNode : public rclcpp::Node 
{
public:
  ParameterNode() : Node("lesson06_01_parameter_node") 
  {
    prefix_ = this->declare_parameter<std::string>("message_prefix", "count = ");
    period_ms_ = this->declare_parameter<int64_t>("period_ms", 1000);

    create_timer();

    parameter_callback_handle_ = add_on_set_parameters_callback(
      std::bind(&ParameterNode::on_parameter_update, this, std::placeholders::_1)
    );
  }

private:
  rcl_interfaces::msg::SetParametersResult on_parameter_update(
    const std::vector<rclcpp::Parameter> & parameters)
  {
    rcl_interfaces::msg::SetParametersResult result;
    result.successful = true;

    for (const auto & param : parameters)
    {
      if (param.get_name() == "period_ms")
      {
        if (param.as_int() <= 0)
        {
          result.successful = false;
          result.reason = "period_ms must be > 0";
          return result;
        }
        period_ms_ = param.as_int();
        RCLCPP_INFO(get_logger(), "Updating prefix to: '%s'", prefix_.c_str());
        create_timer();
      } else if (param.get_name() == "message_prefix")
      {
        prefix_ = param.as_string();
        RCLCPP_INFO(get_logger(), "Updating prefix to : '%s'", prefix_.c_str());
      }
      
    }
    return result;
  }

  void create_timer()
  {
    timer_.reset();
    timer_ = create_wall_timer(
      std::chrono::milliseconds(period_ms_),
      [this]() {
        RCLCPP_INFO(get_logger(), "%s%zu", prefix_.c_str(), count_);
        ++count_;
      });
  }

  std::string prefix_;
  int64_t period_ms_;
  std::size_t count_ = 0;
  rclcpp::TimerBase::SharedPtr timer_;

  rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr parameter_callback_handle_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<ParameterNode>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}

