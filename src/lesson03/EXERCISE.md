# 第三课：发布话题消息

## 学习背景与目标

1. 区分节点名、话题名和消息类型。
2. 用 `create_publisher` 和 `publish` 发出 `std_msgs::msg::String` 消息。
3. 说明定时器回调如何驱动周期发布，以及本题 QoS 的基本含义。

## 概念讲解

话题是具名的数据通道。发布者向话题发送某种固定类型的消息；订阅者可以读取它。`std_msgs::msg::String` 是标准字符串消息，其文本字段为 `data`。`create_publisher<std_msgs::msg::String>(topic, qos)` 创建发布者；对消息对象调用 `publisher->publish(message)` 发送。发布者必须在使用期间保持存活。

本题 QoS 使用 `KeepLast(10)` 保存最近 10 条消息用于发送队列，`reliable()` 尽力保证传输，`durability_volatile()` 不会向晚加入的订阅者重发历史消息。定时器每秒触发一次回调，在回调中构造并发布消息。`rclcpp::spin(node)` 负责处理定时器回调；结束后关闭 ROS 2。

## 最小独立示例

独立示例（与练习话题无关）：

```cpp
auto publisher = node->create_publisher<std_msgs::msg::String>(
  "/status", rclcpp::QoS(rclcpp::KeepLast(5)));
std_msgs::msg::String message;
message.data = "ready";
publisher->publish(message);
```

注意：局部 `message` 在 `publish` 调用后可以销毁；`publisher` 需要在后续发布期间保持存活。本题 lambda 以值捕获发布者，以引用捕获 `count`；`count` 在 `spin` 返回前一直属于 `main` 的作用域。

## 常见错误

忘记 `std_msgs` 依赖；把话题名当成节点名；写入错误的字段；忘记调用 `publish`；销毁 timer 或 publisher 后仍期待周期发送；以为 `volatile` 会保存历史消息。

## 任务与要求

文件职责：[源码](src/lesson03_publisher.cpp) 实现本课节点；CMakeLists.txt 与 package.xml 配置依赖、构建和安装。已完成课程保留现有解答，不重置为骨架。

补全 `src/lesson03_publisher.cpp` 中的 TODO，使节点每秒向 `/lesson03_chatter` 发布一次字符串消息。第一次消息为 `count = 0`，之后依次为 `count = 1`、`count = 2` 等。完成时删除两行 `(void)` 占位语句。

### 要求

1. 使用给定的发布者、定时器和显式 QoS，不修改话题名和周期。
2. 在回调中构造 `std_msgs::msg::String`，设置 `data`，调用 `publish`，然后递增计数。
3. 不增加订阅者、参数或额外节点。

## 构建、运行与预期行为

在工作区根目录的第一个终端：

```bash
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install --packages-select lesson03
source install/setup.bash
ros2 run lesson03 lesson03_publisher
```

在第二个终端：

```bash
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ros2 topic echo /lesson03_chatter
```

输出应依次包含 `data: count = 0`、`data: count = 1`、`data: count = 2`。启动 echo 时可能错过此前发送的消息；重新启动节点即可从 0 观察。结束时按 `Ctrl+C`。

## 验收标准

- [ ] 无新告警地构建成功，节点能启动。
- [ ] `ros2 topic echo` 看到该话题的连续消息，内容和顺序正确。
- [ ] 理解验收关联 L03-Q01～L03-Q04：能解释消息的 `data` 字段、`publish`、`QoS` 和 `timer` 的作用。

## 理解检查问题

题目、回答与反馈统一记录在 [学习问答](../../ROS2_LEARNING_QA.md#第-03-课发布话题消息)：L03-Q01～L03-Q04。理解验收关联以上题号，不在本文件填写答案。

## C++ 语法强化

本课对应的独立语法练习见 [字符串与计数器](cpp_practice/EXERCISE.md)。它单独编译验收，不替代本课 ROS publisher 练习。
