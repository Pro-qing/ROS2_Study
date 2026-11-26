# 第 09 课：测试与验收

本课把之前手动执行的 build、run、ROS 图检查整理成可重复的测试。纯 C++ 逻辑先独立测试，再考虑 ROS 接口检查。

## 题目索引

### lesson09.01：验收层次

区分编译验收、运行验收、ROS 图检查和自动化测试，并说明各自能发现哪类问题。

### lesson09.02：纯 C++ 边界测试

完成 [`lesson09_logic.cpp`](src/lesson09_logic.cpp) 和测试：

1. 实现 `format_count` 的字符串契约。
2. 保留正常输入、空输入语义对应的边界讨论和数值边界测试。
3. 使用 `colcon test --packages-select lesson09` 检查结果。

### lesson09.03：ROS 接口检查

依据 [`lesson09_interface_check.md`](test/lesson09_interface_check.md) 编写有界的节点启动和接口检查流程，验证节点、话题或服务存在及关键输出。

## 验收标准

- [ ] 纯 C++ 测试通过。
- [ ] 至少覆盖正常值、零值和较大边界值。
- [ ] ROS 接口检查不会留下无界运行进程。
- [ ] 能区分源码失败、构建失败、运行失败和环境失败。

## 常用命令

```bash
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install --packages-select lesson09
colcon test --packages-select lesson09
colcon test-result --verbose
```
