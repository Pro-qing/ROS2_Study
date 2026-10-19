# 第四课 C++ 强化：只读引用与值捕获

本练习不依赖 ROS，单独演练第四课回调读取消息文本、并以值捕获外部状态的 C++ 部分。

## 目标

- 用 `const std::string &` 只读访问较大的输入对象。
- 用 lambda 的值捕获保存一个回调所需的副本。
- 区分回调参数与捕获状态。

## 语法提示

`const std::string & text` 表示函数借用现有字符串且不通过此名称修改它。lambda 的 `[prefix]` 会把当前 `prefix` 值复制到闭包对象中；调用 lambda 时，`text` 则是本次调用传入的参数。这里的普通引用与共享指针是不同的类型和生命周期机制。

## 练习

完成 [`practice.cpp`](practice.cpp) 中的 TODO：`describe` 接受只读文本引用并返回前缀为 `received: ` 的字符串；lambda 按值捕获 `prefix` 并输出处理后的文本。输入为 `count = 7` 时，应输出 `received: count = 7`。

编译运行：

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic src/lesson04/cpp_practice/practice.cpp \
  -o src/lesson04/cpp_practice/lesson04_cpp_practice.out
./src/lesson04/cpp_practice/lesson04_cpp_practice.out
```

验收时确认输入没有被修改，捕获的是 `prefix` 的副本，并说明这个普通字符串参数与 ROS 的 `ConstSharedPtr` 并非同一种类型或所有权机制。
