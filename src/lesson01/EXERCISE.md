# 第一课：创建 ROS 2 节点并输出日志

## 学习背景与目标

1. 识别 init、Node 和 shutdown 的职责。
2. 使用节点日志器输出个性化 INFO 消息。

## 概念讲解

初始化使 ROS 上下文可用；Node 提供节点身份与日志器。RCLCPP_INFO 输出 INFO 日志，shutdown 关闭上下文。本题没有持续回调，不要求 spin。

## 最小独立示例

```cpp
RCLCPP_INFO(node->get_logger(), "status: %s", "ready");
```

## 常见错误

未初始化就创建节点；用 std::cout 替代指定日志；遗漏关闭流程。

## 任务与要求

文件职责：[源码](src/lesson01_logger.cpp) 实现本课节点；CMakeLists.txt 与 package.xml 配置依赖、构建和安装。已完成课程保留现有解答，不重置为骨架。

补全 `src/lesson01_logger.cpp` 中的 TODO，让程序运行时通过 ROS 2 的 INFO 日志输出一条介绍自己的消息。

### 要求

1. 保留现有的 `rclcpp::init`、节点创建和 `rclcpp::shutdown` 流程。
2. 使用 `RCLCPP_INFO` 输出消息，不要使用 `std::cout` 代替。
3. 日志内容至少包含一项个性化信息，例如你的名字、学习目标或日期。
4. 不需要添加定时器、话题、服务或其他 ROS 2 功能。

## 构建、运行与预期行为

在当前工作区根目录执行：

```bash
source /path/to/ros/setup.bash
colcon build --symlink-install --packages-select lesson01
source install/setup.bash
ros2 run lesson01 lesson01_logger
```

将 `/path/to/ros/setup.bash` 替换为当前主机实际的 ROS 2 setup 文件。可先运行 `printenv ROS_DISTRO`、`command -v ros2` 和 `command -v colcon` 检查环境。

如果构建报错 `ModuleNotFoundError: No module named 'catkin_pkg'`，先检查当前 Python：

```bash
command -v python3
python3 -c 'import catkin_pkg; print(catkin_pkg.__file__)'
```

确认系统 Python 可用后，可在本次命令中临时指定它；不需要修改系统配置：

```bash
colcon build --symlink-install --packages-select lesson01 --cmake-clean-cache --cmake-args -DPython3_EXECUTABLE="$(command -v python3)"
```

### 运行示例

你的输出格式可能不同，但应能看到类似下面的 INFO 日志：

```text
[INFO] [....] [lesson01_logger]: 我正在学习 ROS 2 Jazzy！
```

先尝试完成代码；完成后告诉我“检查第一课”，我会构建、运行并审查你的实现。

## 验收标准

- [ ] 构建无新告警，节点能正常启动。
- [ ] 输出符合上述要求，运行结束后正常退出。

## 理解检查问题

历史问答未单独留存，见 [问答记录](../../ROS2_LEARNING_QA.md)。不补造历史回答。
