# ROS 2 已学知识目录

本文件只记录已经实际讲授、练习或审查过的内容，不规划未来课程。新课只有在真正开始后才加入目录。

| 课次 | Package / 路径 | 实际学习内容 | 学习证据或当前进展 | 状态 |
| --- | --- | --- | --- | --- |
| 01 | `src/lesson01` | ROS 2 初始化与关闭；创建 `rclcpp::Node`；`get_logger()`；`RCLCPP_INFO` | package 已构建并运行，INFO 日志行为已验证 | 已完成 |
| 02 | `src/lesson02` | wall timer；`std::chrono` 时间字面量；lambda 回调；`rclcpp::spin`；timer 对象生命周期 | 代码审查通过；Jazzy 环境构建无告警，运行时约每秒依次输出 0、1、2、3 | 已完成 |
| 03 | `src/lesson03` | `std_msgs::msg::String`；话题发布者；显式 QoS；定时发布的数据流 | 2026-10-11 构建无告警；echo 收到 Current count: 0～6，接口及 QoS 正确；生命周期与 volatile 解释正确；待改为题目规定的 count = N 并删除占位语句后复查 | 待审查 |
