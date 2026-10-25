#include <iostream>
#include <string>

std::string describe(const std::string & text)
{
  // TODO: 返回一条包含 text 的描述字符串。
  std::string result = "received: " + text;
  return result;
}

int main()
{
  const std::string prefix = "received: ";
  const auto callback = [prefix](const std::string & text) {
    // TODO: 输出 prefix 与 describe(text) 的结果。
    std::cout << describe(text) << std::endl;
  };

  callback("count = 7");
  return 0;
}
