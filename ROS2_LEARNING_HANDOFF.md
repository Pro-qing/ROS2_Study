# ROS 2 学习交接文档

## 学习目标与环境

- 工作区：当前 Git 仓库根目录
- 目标发行版：ROS 2 Jazzy；其它发行版需要先确认兼容性
- 默认语言：C++（`rclcpp`）
- 默认构建系统：`ament_cmake` + `colcon`
- C++ 基线：C++17，逐步引入 RAII、智能指针、lambda、`std::chrono`、容器和测试
- ROS 2 API 基线：优先使用 Jazzy 的 `rclcpp`、标准消息和显式 QoS

## 最近一次环境检查

环境信息属于当前主机，不作为其它主机的固定前提。最近一次检查日期：2026-09-06。

- `ROS_DISTRO`：`jazzy`
- `ros2`：已找到
- `colcon`：已找到
- ROS setup：已找到
- Python 与 `catkin_pkg`：已通过检查

## 学习偏好

- 通过亲手编写小型、可运行的 ROS 2 程序学习。
- 每次只安排一个主要新概念；新练习应复用已经掌握的 C++ 内容。
- 每次学习新知识点时，先讲解用途、核心 API、运行流程、最小示例和常见错误，再给题目与可编译骨架；学习者尝试前不提供练习答案。
- 检查代码时，先构建并运行，再用简洁中文指出问题和文件/行号；除非明确要求，否则不直接修改学习者的解答。
- 只做首次环境检查，不自动安装软件或修改 shell/system 配置。

## 课程目录

| 课次 | Package / 路径 | 主题 | 学习目标 | 状态 |
| --- | --- | --- | --- | --- |
| 01 | `src/lesson01` | 工作区、节点与日志 | 构建并运行节点；理解 `init`、`Node`、logger 和 `shutdown` | 已完成 |
| 02 | `src/lesson02` | wall timer、回调与 `std::chrono` | 周期执行回调；理解 timer 生命周期和 `spin` | 学习中 |
| 03 | `src/lesson03` | publisher、消息类型与基础 QoS | 创建 publisher 并周期发布标准消息 | 未开始 |
| 04 | `src/lesson04` | subscriber、回调参数与所有权 | 接收消息并解释回调数据流 | 未开始 |
| 05 | `src/lesson05` | 发布订阅联调与 topic 检查 | 运行通信节点并使用 CLI 检查 ROS graph | 未开始 |
| 06 | `src/lesson06` | 参数与运行时配置 | 声明、读取和覆盖有类型的参数 | 未开始 |
| 07 | `src/lesson07` | service | 实现并调用请求/响应接口 | 未开始 |
| 08 | `src/lesson08` | action | 处理目标、反馈、结果和取消 | 未开始 |
| 09 | `src/lesson09` | launch、参数文件与安装规则 | 可复现地启动多节点系统 | 未开始 |
| 10 | `src/lesson10` | executor、callback group 与并发基础 | 理解并控制回调执行方式 | 未开始 |
| 11 | `src/lesson11` | ROS 2 测试 | 为节点或接口编写自动化测试 | 未开始 |
| 12 | `src/lesson12` | 综合小项目 | 综合通信、配置、launch 和测试 | 未开始 |

## 当前练习

- 文件：`src/lesson02/`
- 主题：使用 `rclcpp` wall timer 周期性执行回调
- 当前状态：题目说明和可编译代码骨架已创建，等待学习者完成 TODO 后审查

后续课程可根据每次代码审查结果拆分、合并或调整难度，但已使用的课号保持稳定。
