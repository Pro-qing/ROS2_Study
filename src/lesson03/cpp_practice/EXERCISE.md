# 第三课 C++ 强化：字符串与计数器

本练习独立于 ROS 消息类型，练习第三课发布前需要的 C++ 工作：维护计数，并把数值组成文本。

## 目标

- 使用 `std::to_string` 将数值转成文本。
- 用 `std::string` 拼接字段，并在多次调用中更新计数。

## 语法提示

`std::to_string(value)` 会把整数转成 `std::string`。字符串可用 `+` 拼接，例如 `std::string("item ") + std::to_string(index)`。先构造并返回完整字符串，再由调用方决定如何显示或发送它。

## 练习

完成 [`practice.cpp`](practice.cpp) 中的 TODO：`make_message` 返回 `count = N` 格式的文本，调用者每次调用后递增计数。三次调用应得到 `count = 0`、`count = 1`、`count = 2`。

编译运行：

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic src/lesson03/cpp_practice/practice.cpp \
  -o src/lesson03/cpp_practice/lesson03_cpp_practice.out
./src/lesson03/cpp_practice/lesson03_cpp_practice.out
```

验收时检查消息文本、计数更新顺序及函数参数的用途。对应 ROS 课程时，返回文本会放入消息的 `data` 字段，再交给 publisher。
