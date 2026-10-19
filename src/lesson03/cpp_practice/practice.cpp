#include <cstddef>
#include <iostream>
#include <string>

std::string make_message(std::size_t count)
{
  // TODO: 返回格式为 "count = N" 的字符串。
  std::string message = "count = " + std::to_string(count);
  // (void)count;
  return message;
}

int main()
{
  std::size_t count = 0;
  for (int i = 0; i < 3; ++i) {
    std::cout << make_message(count) << '\n';
    ++count;
  }
  return 0;
}
