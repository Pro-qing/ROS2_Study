# 第一课：创建 ROS 2 节点并输出日志

## 学习目标

理解一个最小 ROS 2 C++ 程序的基本结构：初始化 ROS 2、创建 `Node`、使用日志宏输出信息，以及正常关闭 ROS 2。

## 任务

补全 `src/lesson01_logger.cpp` 中的 TODO，让程序运行时通过 ROS 2 的 INFO 日志输出一条介绍自己的消息。

## 要求

1. 保留现有的 `rclcpp::init`、节点创建和 `rclcpp::shutdown` 流程。
2. 使用 `RCLCPP_INFO` 输出消息，不要使用 `std::cout` 代替。
3. 日志内容至少包含一项个性化信息，例如你的名字、学习目标或日期。
4. 不需要添加定时器、话题、服务或其他 ROS 2 功能。

## 构建与运行

在工作区根目录 `/home/proqing/ROS2_Study` 执行：

```bash
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install --packages-select lesson01
source install/setup.bash
ros2 run lesson01 lesson01_logger
```

如果构建报错 `ModuleNotFoundError: No module named 'catkin_pkg'`，说明当前 shell 使用了 Anaconda Python。此时将第二行替换为下面这条命令即可，不需要修改系统配置：

```bash
colcon build --symlink-install --packages-select lesson01 --cmake-clean-cache --cmake-args -DPython3_EXECUTABLE=/usr/bin/python3
```

## 运行示例

你的输出格式可能不同，但应能看到类似下面的 INFO 日志：

```text
[INFO] [....] [lesson01_logger]: 我正在学习 ROS 2 Jazzy！
```

先尝试完成代码；完成后告诉我“检查第一课”，我会构建、运行并审查你的实现。
