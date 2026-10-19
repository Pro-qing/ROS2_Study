#include <iostream>
#include <string>

std::string describe(const std::string & text)
{
  // TODO: 回傳一條包含 text 的描述字串。
  (void)text;
  return "TODO";
}

int main()
{
  const std::string prefix = "received: ";
  const auto callback = [prefix](const std::string & text) {
    // TODO: 輸出 prefix 與 describe(text) 的結果。
    (void)prefix;
    (void)text;
  };

  callback("count = 7");
  return 0;
}
