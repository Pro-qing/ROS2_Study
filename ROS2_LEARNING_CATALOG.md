# ROS 2 已学知识目录

本文件只记录已经实际讲授、练习或审查过的内容，不规划未来课程。新课只有在真正开始后才加入目录。

思考题、理解验收问题、学习者原答和反馈统一见 [学习问答记录](ROS2_LEARNING_QA.md)。

| 课次 | Package / 路径 | 实际学习内容 | 学习证据或当前进展 | 状态 |
| --- | --- | --- | --- | --- |
| 01 | `src/lesson01` | ROS 2 初始化与关闭；创建 `rclcpp::Node`；`get_logger()`；`RCLCPP_INFO` | package 已构建并运行，INFO 日志行为已验证 | 已完成 |
| 02 | `src/lesson02` | wall timer；`std::chrono` 时间字面量；lambda 回调；`rclcpp::spin`；timer 对象生命周期 | 代码审查通过；Jazzy 环境构建无告警，运行时约每秒依次输出 0、1、2、3 | 已完成 |
| 03 | `src/lesson03` | `std_msgs::msg::String`；话题发布者；显式 QoS；定时发布的数据流 | 2026-10-18 复查构建无新告警；echo 收到 count = 0 及连续 2、3、4；接口和 RELIABLE / VOLATILE 正确，占位语句已清理；count 生命周期、volatile、timer 存活与 (void)timer 解释通过 | 已完成 |
| 04 | `src/lesson04` | 话题订阅；create_subscription；ConstSharedPtr 回调；logger 值捕获；spin 调度及通信匹配 | 2026-10-18 两课构建无新告警，真实发布者联调收到 count = 0～4；接口及 QoS 正确；停止发布检查通过；spin、ConstSharedPtr 和 logger 值捕获解释正确 | 已完成 |
| 04 C++ | `src/lesson04/cpp_practice` | `const std::string &` 只读引用；lambda 值捕获；回调参数与捕获状态 | 2026-10-25 构建无告警，运行输出符合示例；`describe` 仍保留 TODO，函数契约与练习文档存在前缀重复歧义 | 待审查 |
