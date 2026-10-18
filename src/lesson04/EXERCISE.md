# 第 04 课：话题订阅回调

## 学习背景与目标

第三课已经完成发布、定时器和显式 QoS。本课学习订阅者：

1. 创建 String 订阅，接收第三课发布的消息。
2. 用只读消息指针编写回调，并输出收到的 data。
3. 解释 spin、订阅对象生命周期以及通信匹配条件。

## 概念讲解

订阅者接收指定话题和类型的数据。create_subscription<Message>(topic, qos, callback)
返回订阅对象的共享指针；保留它，使订阅在 spin 期间存活。
注册回调不会立刻调用它。数据到达后，执行器在 spin 中调度回调；本课不需要新增定时器或手写轮询循环。

运行流程：第三课定时器 → publish → /lesson03_chatter → 第四课订阅 → spin 调度 → 回调输出。

回调可写成 void(std_msgs::msg::String::ConstSharedPtr message)。
ConstSharedPtr 是指向 const 消息的共享指针：通过 message->data 读取文本，不修改消息。
参数按值传递，在回调执行期间保持消息存活。不要将局部参数的引用保存到回调外。

logger 用 [logger] 按值捕获，回调保存自己的日志器副本，不依赖局部 logger 的引用。
本课不捕获 node，避免让订阅回调反过来持有节点。

双方话题名和消息类型必须相同，QoS 必须兼容。沿用可靠传输 reliable、
不补发历史消息的 volatile，以及 KeepLast(10)（最多保留最近 10 条待处理消息）。
reliable 涉及传输可靠性，不保证应用处理无限快；队列深度也不是晚加入者的历史存档。

## 最小独立示例

```cpp
auto inspect = [logger](std_msgs::msg::String::ConstSharedPtr message) {
  RCLCPP_INFO(logger, "text length: %zu", message->data.size());
};
```

这里定义了回调，但没有注册订阅，所以不会自动执行。
本题输出文本时，日志格式使用 %s，std::string 通过 c_str() 提供相应的 C 字符串指针。
不要把消息文本本身作为日志格式串。

## 常见错误

- 把节点名 lesson04_subscriber 当作话题名。
- 写成 message.data，忽略 message 是指针，应使用 ->。
- 创建订阅后丢弃返回指针，或忘记 spin。
- 使用不兼容的 QoS，或期待 volatile 补发 count = 0。
- 在接收回调里自行计数，输出与真实收到的数据不一致。

## 任务与要求

文件职责：[源码](src/lesson04_subscriber.cpp) 实现本课节点；CMakeLists.txt 与 package.xml 配置依赖、构建和安装。已完成课程保留现有解答，不重置为骨架。

补全 src/lesson04_subscriber.cpp 的两个 TODO：

- 订阅 /lesson03_chatter，类型为 std_msgs::msg::String。
- 显式设置 KeepLast(10)、reliable()、durability_volatile()。
- 回调按值捕获 logger，接受 String::ConstSharedPtr。
- 每收到一条消息，输出 received: count = N，N 必须来自消息本身。
- 删除 (void)logger 占位语句；保持订阅对象在 spin 期间存活。

文件职责：源码负责订阅；CMakeLists.txt 和 package.xml 已配置依赖、目标及安装，无需补写。
初始骨架可以编译并启动，但没有订阅，也不会输出接收日志。此课先在两个终端分别运行，暂不要求 launch。

## 构建、运行与预期行为

工作区根目录：

```bash
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install --packages-select lesson03 lesson04
source install/setup.bash
ros2 run lesson04 lesson04_subscriber
```

另一个终端：

```bash
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ros2 run lesson03 lesson03_publisher
```

预期第四课日志依次包含 received: count = 0、received: count = 1 等。
发现可能需要时间，首条数字允许大于 0。两个终端都用 Ctrl+C 停止。

第三个终端 source 同样的环境后，可运行：

```bash
ros2 node list
ros2 topic info /lesson03_chatter --verbose
```

## 验收标准

- [ ] 构建无新告警，订阅节点能启动。
- [ ] 只运行订阅节点时不周期输出；发布者启动后才输出收到的消息。
- [ ] 话题有第三课的发布端和第四课的订阅端，类型与 QoS 正确。
- [ ] 停止发布者后，待在途或队列消息处理完，不再产生新的接收日志。
- [ ] 理解验收关联 L04-Q01～L04-Q05：能解释 ConstSharedPtr、[logger]、subscription 和 spin 各自的作用。

## 理解检查问题

题目、回答与反馈统一记录在 [学习问答](../../ROS2_LEARNING_QA.md#第-04-课话题订阅回调)：L04-Q01～L04-Q05。理解验收关联以上题号，不在本文件填写答案。
