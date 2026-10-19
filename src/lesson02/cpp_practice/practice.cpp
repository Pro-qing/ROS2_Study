#include <cstddef>
#include <iostream>

int main()
{
  std::size_t count = 0;

  auto callback = [&count]() {
    // TODO: 输出 count 当前值，然后递增 count。
    std::cout << count << std::endl;
    count++;
  };

  callback();
  callback();
  callback();
  return 0;
}
