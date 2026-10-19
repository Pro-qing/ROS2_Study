# 第二课 C++ 强化：lambda、引用捕获与生命周期

本练习不启动 ROS。它单独演练第二课定时器回调使用 lambda 访问外部计数器的 C++ 部分。

## 目标

- 定义一个捕获局部变量的 lambda。
- 在被捕获对象仍存活时调用回调，并观察状态变化。

## 语法提示

`[&count]` 表示 lambda 通过引用访问外部的 `count`，所以递增会改动原变量。lambda 的花括号是回调函数体，只有调用 `callback()` 时才执行。引用捕获不延长 `count` 的生命周期，因此变量必须活到最后一次回调调用结束。

## 练习

完成 [`practice.cpp`](practice.cpp) 中的 TODO：让回调每次输出当前计数并递增；连续调用三次应输出 0、1、2。`count` 和回调都在 `main` 中，回调调用完成前 `count` 必须保持存活。

编译运行：

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic src/lesson02/cpp_practice/practice.cpp -o /tmp/lesson02_cpp_practice
/tmp/lesson02_cpp_practice
```

验收时确认计数顺序正确，并能解释引用捕获不拥有变量，以及为什么本例调用回调时引用仍有效。对应 ROS 课程的 timer 由 spin 驱动；不要把此练习误认为真实定时器。
