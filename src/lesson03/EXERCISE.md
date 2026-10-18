# 第三课：发布话题消息

## 学习目标

1. 区分节点名、话题名和消息类型。
2. 用 `create_publisher` 和 `publish` 发出 `std_msgs::msg::String` 消息。
3. 说明定时器回调如何驱动周期发布，以及本题 QoS 的基本含义。

## 概念

话题是具名的数据通道。发布者向话题发送某种固定类型的消息；订阅者可以读取它。`std_msgs::msg::String` 是标准字符串消息，其文本字段为 `data`。`create_publisher<std_msgs::msg::String>(topic, qos)` 创建发布者；对消息对象调用 `publisher->publish(message)` 发送。发布者必须在使用期间保持存活。

本题 QoS 使用 `KeepLast(10)` 保存最近 10 条消息用于发送队列，`reliable()` 尽力保证传输，`durability_volatile()` 不会向晚加入的订阅者重发历史消息。定时器每秒触发一次回调，在回调中构造并发布消息。`rclcpp::spin(node)` 负责处理定时器回调；结束后关闭 ROS 2。

独立示例（与练习话题无关）：

```cpp
auto publisher = node->create_publisher<std_msgs::msg::String>(
  "/status", rclcpp::QoS(rclcpp::KeepLast(5)));
std_msgs::msg::String message;
message.data = "ready";
publisher->publish(message);
```

注意：局部 `message` 在 `publish` 调用后可以销毁；`publisher` 需要在后续发布期间保持存活。本题 lambda 以值捕获发布者，以引用捕获 `count`；`count` 在 `spin` 返回前一直属于 `main` 的作用域。

常见错误：忘记 `std_msgs` 依赖；把话题名当成节点名；写入错误的字段；忘记调用 `publish`；销毁 timer 或 publisher 后仍期待周期发送；以为 `volatile` 会保存历史消息。

## 任务

补全 `src/lesson03_publisher.cpp` 中的 TODO，使节点每秒向 `/lesson03_chatter` 发布一次字符串消息。第一次消息为 `count = 0`，之后依次为 `count = 1`、`count = 2` 等。完成时删除两行 `(void)` 占位语句。

## 要求

1. 使用给定的发布者、定时器和显式 QoS，不修改话题名和周期。
2. 在回调中构造 `std_msgs::msg::String`，设置 `data`，调用 `publish`，然后递增计数。
3. 不增加订阅者、参数或额外节点。

## 构建与验证

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

## 验收

- [ ] 无新告警地构建成功，节点能启动。
- [ ] `ros2 topic echo` 看到该话题的连续消息，内容和顺序正确。
- [ ] 能解释消息的 `data` 字段、`publish`、`QoS` 和 `timer` 的作用。

思考：为什么晚启动的 `ros2 topic echo` 不一定能看到 `count = 0`？为什么回调中的 `count` 引用在本程序运行期间有效？

ans.1: 晚启动的 `ros2 topic echo` 不一定看到 `count = 0`
    关键在发布者的 `QoS`:
    `rclcpp::QoS(rclcpp::KeepLast(10)).reliable().durability_volatile()`
    其中的 `durability_volatile()` 表示： 发布者不会给晚加入的订阅者补发它加入之前已经发布过的消息。

ans.2: 回调中的 `count` 引用有效，
    因为 `count` 是 `main` 函数里的局部变量：
    `std::size_t count = 0;`
    它的生命周期从定义开始，一直到 `main` 返回才结束。
    `lambda` 捕获的是：
    `[publisher, &count]() {...}`
    `&count` 是引用捕获，不拥有对象，只是引用 `main` 栈帧里的那个 `count`。而定时器回调由：
    `rclcpp::spin(node);` 驱动。 `spin(node)` 就在 `main` 里面阻塞运行，所有 `timer` 回调都发生在 `spin` 返回之前，也就是 `main` 返回之前。
    所以回调执行时：
    `main` 的栈帧仍然存在；
    `count` 仍然活着；
    `&count` 仍然指向有效对象。
    当 `rclcpp::shutdown()` 使 `spin` 返回后，不会再触发 `timer` 回调；随后 main 返回，局部变量才销毁。因此本程序里这个引用是安全的。