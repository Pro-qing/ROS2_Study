# 第二课：使用定时器回调

## 学习背景与目标

1. 用 1 秒 wall timer 周期输出计数。
2. 解释回调、spin 与 timer 的生命周期关系。

## 概念讲解

wall timer 按周期产生就绪事件，spin 中的执行器调度回调。回调先读取计数再递增；timer 的共享所有者需在 spin 期间存活。

## 最小独立示例

```cpp
using namespace std::chrono_literals;
auto delay = 250ms;  // chrono 时间字面量示例，不是本题周期。
(void)delay;
```

## 常见错误

遗漏 spin；丢弃 timer 所有者；先递增导致第一条输出为 1；捕获已失效的局部引用。

## 任务与要求

文件职责：[源码](src/lesson02_timer.cpp) 实现本课节点；CMakeLists.txt 与 package.xml 配置依赖、构建和安装。已完成课程保留现有解答，不重置为骨架。

补全 `src/lesson02_timer.cpp` 中的 TODO，使节点每隔约 1 秒输出一次当前计数，并将计数递增。

### 要求

1. 保留现有的 `create_wall_timer`、`rclcpp::spin` 和关闭流程。
2. 使用 `RCLCPP_INFO` 输出日志，不要使用 `std::cout`。
3. 第一次回调输出 `count = 0`，之后每次递增 1。
4. 定时器周期保持为 1 秒；不添加 publisher、subscriber 或参数。

## 构建、运行与预期行为

在当前工作区根目录执行：

```bash
source /path/to/ros/setup.bash
colcon build --symlink-install --packages-select lesson02
source install/setup.bash
ros2 run lesson02 lesson02_timer
```

将 `/path/to/ros/setup.bash` 替换为当前主机实际的 ROS 2 setup 文件；skill 会在环境检查时帮助识别它。

程序会持续运行。观察到至少 3 次日志后按 `Ctrl+C` 结束。

### 运行示例

时间戳会不同，但日志应类似：

```text
[INFO] [...] [lesson02_timer]: count = 0
[INFO] [...] [lesson02_timer]: count = 1
[INFO] [...] [lesson02_timer]: count = 2
```

先独立完成代码；完成后告诉我“检查第二课”，我会构建、运行并审查你的实现。

## 验收标准

- [ ] 构建无新告警，节点能正常启动。
- [ ] 输出符合上述要求，运行结束后正常退出。

## 理解检查问题

历史问答未单独留存，见 [问答记录](../../ROS2_LEARNING_QA.md)。不补造历史回答。
