# ROS 2 学习交接文档

## 学习环境

- 工作区：`/home/proqing/ROS2_Study`
- 目标发行版：ROS 2 Jazzy
- 默认语言：C++（`rclcpp`）
- 默认构建系统：`ament_cmake` + `colcon`
- 环境检查：已通过（`ROS_DISTRO=jazzy`，`ros2` 位于 `/opt/ros/jazzy/bin/ros2`，`colcon` 位于 `/usr/bin/colcon`，Jazzy setup 文件存在）
- 构建环境：`python3` 和 `catkin_pkg` 均来自 `/usr/bin/python3`

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

1. 工作区、ROS 2 package 和日志节点
2. `rclcpp` 节点生命周期与定时器回调
3. publisher 发布话题
4. subscriber 订阅话题
5. 参数（parameters）
6. service 客户端与服务端
7. action 客户端与服务端
8. launch 文件
9. 综合小项目

根据每次代码审查结果调整顺序和难度。
