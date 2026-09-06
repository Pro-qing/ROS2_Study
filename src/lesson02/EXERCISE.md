# 第二课：使用定时器回调

## 学习目标

理解 ROS 2 节点如何通过 wall timer 周期性执行回调函数，并在回调中维护一个简单的计数器。

## 任务

补全 `src/lesson02_timer.cpp` 中的 TODO，使节点每隔约 1 秒输出一次当前计数，并将计数递增。

## 要求

1. 保留现有的 `create_wall_timer`、`rclcpp::spin` 和关闭流程。
2. 使用 `RCLCPP_INFO` 输出日志，不要使用 `std::cout`。
3. 第一次回调输出 `count = 0`，之后每次递增 1。
4. 定时器周期保持为 1 秒；不添加 publisher、subscriber 或参数。

## 构建与运行

在当前工作区根目录执行：

```bash
source /path/to/ros/setup.bash
colcon build --symlink-install --packages-select lesson02
source install/setup.bash
ros2 run lesson02 lesson02_timer
```

将 `/path/to/ros/setup.bash` 替换为当前主机实际的 ROS 2 setup 文件；skill 会在环境检查时帮助识别它。

程序会持续运行。观察到至少 3 次日志后按 `Ctrl+C` 结束。

## 运行示例

时间戳会不同，但日志应类似：

```text
[INFO] [...] [lesson02_timer]: count = 0
[INFO] [...] [lesson02_timer]: count = 1
[INFO] [...] [lesson02_timer]: count = 2
```

先独立完成代码；完成后告诉我“检查第二课”，我会构建、运行并审查你的实现。
