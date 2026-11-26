# 第 10 课：Executor 与综合复习

本课回顾 timer、subscription、spin、对象生命周期、QoS 和验收流程，并观察 executor 如何调度多个回调。多线程只在理解单线程模型后按需要引入。

## 题目索引

### lesson10.01：spin 与 executor

解释 `rclcpp::spin`、executor、timer 回调和 subscription 回调的关系，并说明省略 spin 的结果。

### lesson10.02：executor 与 callback group

完成 [`lesson10_executor_demo.cpp`](src/lesson10_executor_demo.cpp) 的说明和实验：

1. 观察单线程 executor 如何调度两个回调。
2. 比较 callback group、单线程 executor 和多线程 executor 的职责。
3. 只有出现具体并发需求时，才增加多线程实现。

### lesson10.03：综合验收顺序

针对一个 publisher/subscriber 或 service 节点，列出并执行从源码、构建、运行到 ROS 接口的验收顺序，覆盖数据流、QoS、生命周期、错误处理和可测试性。

## 验收标准

- [ ] 节点构建无新警告。
- [ ] 能观察 timer 和 subscription 的调度行为。
- [ ] 能说明 executor 不等于回调本身，spin 负责进入调度循环。
- [ ] 综合验收顺序能区分源码、构建、运行和 ROS 图问题。

## 常用命令

```bash
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install --packages-select lesson10
source install/setup.bash
ros2 run lesson10 lesson10_executor_demo
```
