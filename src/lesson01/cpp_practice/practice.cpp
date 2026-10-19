#include <iostream>
#include <string>

std::string make_status(std::string goal)
{
  // TODO: 创建并返回一条包含 goal 的介绍文字。
  std::string status = "I am currently working on: " + goal;
  return status;
}

int main()
{
  const std::string goal = "learn ROS 2 logging";
  const std::string status = make_status(goal);
  std::cout << status << '\n';
  return 0;
}
