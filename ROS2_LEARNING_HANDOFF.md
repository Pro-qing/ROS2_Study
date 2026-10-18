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

## 文档分工

- 各课 EXERCISE.md：教学与任务说明，包含可执行验收标准和问答题号链接；不填写回答或审查结果。
- [ROS2_LEARNING_QA.md](ROS2_LEARNING_QA.md)：按课次保存思考题、理解验收题、原答、反馈和状态。新提问及聊天回答及时归档。
- 目录：已学知识与进度摘要；本交接文档：当前证据、问题与下一步。
- 2026-10-18 已迁移第三、四课原答并规范四课 EXERCISE.md；历史未单独记录的解释标为补充项，不撤销已完成结论。

## 当前练习

- 文件：`src/lesson04/`
- 主题：使用 String 订阅回调接收第三课发布者的数据
- 当前状态：2026-10-18 第四课代码、构建、真实发布者联调与理解验收均通过，已完成。

## 当前观察

- 已验证：第一课的初始化、节点、日志和关闭流程；第二课代码正确使用 1 秒 wall timer，在回调中先输出计数再递增。`colcon build --symlink-install --packages-select lesson02` 无告警；沙箱外运行约 5 秒，观察到 0、1、2、3 顺序输出。
- 环境备注：默认 ROS 日志目录只读，验证时用 `ROS_LOG_DIR=/tmp`；沙箱内 DDS 网络权限不足，沙箱外运行无该报错。这些不是源码问题。
- 第三课验证：`colcon build --symlink-install --packages-select lesson03` 成功且无新告警；沙箱外限时执行 `ros2 run` 和 `ros2 topic echo`，连续收到 `Current count: 0` 至 `Current count: 6`；`ros2 topic info --verbose` 确认话题 `/lesson03_chatter`、类型 `std_msgs/msg/String`、发布节点 `lesson03_publisher`、RELIABLE / VOLATILE。
- 第三课 2026-10-18 复查：消息格式已改为 `count = N`，回调内占位语句与 TODO 已删除。构建成功且无新告警；节点启动正常，echo 首次收到 `count = 0`，随后另一 echo 连续收到 2、3、4；话题类型、节点名和 RELIABLE / VOLATILE 符合要求。DDS 报告 History (Depth) 为 UNKNOWN，深度 10 由源码确认。限时验证后节点与 echo 均已停止，未修改学习者源码。
- 学习者在问答记录中已正确解释 volatile 不补发历史消息，以及 `main` 中 `count` 在阻塞的 `spin` 期间保持存活。关于 `shutdown` 的顺序可更精确：本代码通常由 Ctrl+C 的默认信号处理触发 shutdown，使 spin 返回；main 末尾再调用 shutdown。
- 2026-10-18 理解验收：学习者正确解释 timer 需保持存活，以及 `(void)timer` 不影响生命周期。补充精确表述：销毁最后一个 shared_ptr 所有者才使对象析构；create_wall_timer 返回具体 WallTimer 回调类型的 SharedPtr，可转换为 TimerBase::SharedPtr。无需要求记忆模板细节。尚未观察到需要额外补强的 ROS 2 代码薄弱点。

## 下一步指导方向

第四课已完成。可基于手动启动两节点的经验学习 launch，解决统一启动问题；尚未创建或讲授新课。不必因残留 TODO 注释阻塞完成，建议日常收尾清理。审查未修改学习者解答。

- 第四课准备证据：C++17 单文件骨架构建无新告警；限时启动正常，尚无订阅和接收输出是预期行为。讲解与命令见 src/lesson04/EXERCISE.md；不将骨架验证视为解答通过。

- 第四课解答审查（2026-10-18）：lesson04 构建无新告警，类型、话题、QoS、logger 值捕获与 ConstSharedPtr 正确；仅启动时输出一次 ready，CLI 以 1Hz 发布 count = 42 时连续正确接收四条，停止发布并排空后两秒无新日志。topic info 验证订阅端 lesson04_subscriber、String、RELIABLE / VOLATILE；深度由源码确认。进程均停止。第三课因第 29 行日志末尾漏分号构建失败，未使用旧二进制冒充联调。问答记录中对无 timer 与无 spin 的解释基本正确，应精确为执行器调度回调。第四课尚有已完成 TODO 注释和一处缩进，可收尾清理。

- 第四课最终验收（2026-10-18）：学习者正确解释 ConstSharedPtr 等价于 shared_ptr<const Message>，以及 [logger] 保存副本；第三课分号已修复。两课构建无新告警，真实发布者联调收到 count = 0、1、2、3、4；topic info 确认一发布端 lesson03_publisher、一订阅端 lesson04_subscriber，类型与 RELIABLE / VOLATILE 正确。所有验证进程已停止。残留已完成 TODO 注释仅为非阻塞整理建议。
