# ROS 2 学习交接文档

## 学习目标与环境

- 工作区：当前 Git 仓库根目录
- 目标发行版：ROS 2 Jazzy；其它发行版需要先确认兼容性
- 默认语言：C++（`rclcpp`）
- 默认构建系统：`ament_cmake` + `colcon`
- C++ 基线：C++17，逐步引入 RAII、智能指针、lambda、`std::chrono`、容器和测试
- ROS 2 API 基线：优先使用 Jazzy 的 `rclcpp`、标准消息和显式 QoS

## 最近一次环境检查

环境信息属于当前主机，不作为其它主机的固定前提。最近一次检查日期：2026-10-09。

- `ROS_DISTRO`：`jazzy`
- `ros2`：已找到
- `colcon`：已找到
- ROS setup：已找到
- Python 与 `catkin_pkg`：已通过检查

## 学习偏好

- 通过亲手编写小型、可运行的 ROS 2 程序学习。
- 每次只安排一个主要新概念；新练习应复用已经掌握的 C++ 内容。算法可涵盖通用算法和机器人常用算法，按实际学习情况选择。
- 简单练习可以只用单个源文件；算法需要独立验证、多个节点协作或存在共享代码时，按职责使用多文件。
- 涉及算法时，将纯 C++ 算法与 ROS 2 接入分开讲解、编写和验收；纯 ROS 课程不强加算法。保持一条课程线和现有学习记录。
- 在 launch 专题中学习编写 launch 文件；多节点协作或需要统一参数、重映射时使用并验收 launch，简单单节点练习可以使用 `ros2 run`。
- 每次学习新知识点时，先讲解用途、相关 API 或算法接口、运行流程、最小示例和常见错误，再给题目与可编译骨架；学习者尝试前不提供练习答案。
- 检查代码时，先构建，再分别检查适用的算法边界情况、节点和 launch 行为；用简洁中文指出问题和文件/行号。除非明确要求，否则不直接修改学习者的解答。
- 只做首次环境检查，不自动安装软件或修改 shell/system 配置。

## 学习目录

实际学习过的内容单独记录在 `ROS2_LEARNING_CATALOG.md`。该文件不记录未来课程或预设路线。

## 当前练习

- 文件：`src/lesson03/`
- 主题：使用 `rclcpp` 发布者周期性发布 `std_msgs::msg::String`
- 当前状态：2026-10-11 已审查，发布逻辑和接口正确；待修正消息格式、删除遗留占位语句后复查。

## 当前观察

- 已验证：第一课的初始化、节点、日志和关闭流程；第二课代码正确使用 1 秒 wall timer，在回调中先输出计数再递增。`colcon build --symlink-install --packages-select lesson02` 无告警；沙箱外运行约 5 秒，观察到 0、1、2、3 顺序输出。
- 环境备注：默认 ROS 日志目录只读，验证时用 `ROS_LOG_DIR=/tmp`；沙箱内 DDS 网络权限不足，沙箱外运行无该报错。这些不是源码问题。
- 第三课验证：`colcon build --symlink-install --packages-select lesson03` 成功且无新告警；沙箱外限时执行 `ros2 run` 和 `ros2 topic echo`，连续收到 `Current count: 0` 至 `Current count: 6`；`ros2 topic info --verbose` 确认话题 `/lesson03_chatter`、类型 `std_msgs/msg/String`、发布节点 `lesson03_publisher`、RELIABLE / VOLATILE。
- 第三课要求偏差：源文件第 25 行消息前缀应为 `count = `；第 29～30 行 `(void)` 占位语句及第 23 行已完成的 TODO 仍保留。审查未改学习者源码。
- 学习者在 EXERCISE.md 中已正确解释 volatile 不补发历史消息，以及 `main` 中 `count` 在阻塞的 `spin` 期间保持存活。关于 `shutdown` 的顺序可更精确：本代码通常由 Ctrl+C 的默认信号处理触发 shutdown，使 spin 返回；main 末尾再调用 shutdown。
- 待确认：为何必须保留 timer 对象；尚未观察到需要额外补强的 ROS 2 代码薄弱点。

## 下一步指导方向

先由学习者修正第三课消息格式和遗留占位语句，再复查验收。通过后可学习话题订阅回调，直接复用已验证的 String 发布者作为输入；新课尚未创建或讲授，不加入目录。
