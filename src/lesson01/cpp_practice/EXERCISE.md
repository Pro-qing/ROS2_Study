# 第一课 C++ 强化：函数与作用域

本练习独立于 ROS 节点，用普通 C++ 函数组织一条状态消息。它对应第一课把程序入口、节点设置和日志输出分开的思路。

## 目标

- 定义并调用一个返回 `std::string` 的函数。
- 区分函数局部变量与调用者中的变量作用域。

## 语法提示

函数声明包含返回类型、名称和参数列表，例如 `int add(int left, int right)`。`return` 把结果交还给调用者；函数内部声明的局部变量在函数返回后不能继续使用。`main` 可以把函数返回值保存到自己的局部变量，再负责输出。

## 练习

完成 [`practice.cpp`](practice.cpp) 中的 TODO：让 `make_status` 根据传入的学习目标返回一条介绍文本，并由 `main` 输出它。不要在 `make_status` 中直接打印；返回值由调用者负责使用。

编译运行：

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic src/lesson01/cpp_practice/practice.cpp \
  -o src/lesson01/cpp_practice/lesson01_cpp_practice.out
./src/lesson01/cpp_practice/lesson01_cpp_practice.out
```

预期输出包含学习目标文字。验收时确认函数有返回值、局部变量未在作用域外使用，并能说明 main 如何使用返回结果。
