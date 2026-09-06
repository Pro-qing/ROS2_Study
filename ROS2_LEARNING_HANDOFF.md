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
- 创建新练习时，先写题目说明、要求、示例和可编译骨架；学习者尝试前不提供答案。
- 检查代码时，先构建并运行，再用简洁中文指出问题和文件/行号；除非明确要求，否则不直接修改学习者的解答。
- 只做首次环境检查，不自动安装软件或修改 shell/system 配置。

## 已完成练习

| 项目 | 题目 | 已练习的知识点 | 状态 |
| --- | --- | --- | --- |
| `src/lesson01` | 创建 ROS 2 节点并输出 INFO 日志 | `rclcpp::init`、创建 `Node`、`get_logger()`、`RCLCPP_INFO`、`rclcpp::shutdown` | 已完成并验证 |

## 当前练习

- 文件：`src/lesson02/`
- 主题：使用 `rclcpp` wall timer 周期性执行回调
- 当前状态：题目说明和可编译代码骨架已创建，等待学习者完成 TODO 后审查

## 建议学习路线

1. 工作区、ROS 2 package、节点和日志
2. C++ lambda、`std::chrono` 与 `rclcpp` 定时器
3. publisher、消息类型与 QoS
4. subscriber、回调参数与对象生命周期
5. 参数和运行时配置
6. service 客户端与服务端
7. action 客户端与服务端
8. launch、参数文件和安装规则
9. executor、callback group 与并发基础
10. 测试和综合小项目

根据每次代码审查结果调整顺序和难度。
