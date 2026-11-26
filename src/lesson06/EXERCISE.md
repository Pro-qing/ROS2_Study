# 第 06 课：参数

本课把第三课的计数发布思路改造成可配置节点，重点学习参数的声明、类型和运行时覆盖。当前源码是可编译 TODO 框架。

## 题目索引

### lesson06.01：参数声明与读取

解释为什么参数应先声明再读取，并区分默认值、命令行覆盖值和源码硬编码常量。回答记录在 [QA](../../ROS2_LEARNING_QA.md) 中。

### lesson06.02：类型明确的参数节点

完成 [`lesson06_parameter_node.cpp`](src/lesson06_parameter_node.cpp)：

1. 确认 `message_prefix` 和 `period_ms` 的参数类型与默认值。
2. 让 timer 使用读取到的周期，并让日志使用读取到的前缀。
3. 分别验证默认参数和命令行覆盖参数。

### lesson06.03：YAML 参数文件

使用 [`lesson06_parameter_node.yaml`](config/lesson06_parameter_node.yaml)：

1. 修改 YAML 中的参数值。
2. 使用 `--ros-args --params-file` 启动节点。
3. 通过日志或 `ros2 param get` 检查实际参数类型和值，并说明参数文件到节点的配置流。

## 验收标准

- [ ] package 构建无新警告。
- [ ] 默认参数能驱动节点运行。
- [ ] 命令行和 YAML 覆盖值能被节点读取。
- [ ] 能说明声明参数、读取参数和覆盖参数之间的区别。

## 常用命令

```bash
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install --packages-select lesson06
source install/setup.bash
ros2 run lesson06 lesson06_parameter_node
ros2 run lesson06 lesson06_parameter_node --ros-args -p message_prefix:="cli count = " -p period_ms:=250
ros2 run lesson06 lesson06_parameter_node --ros-args --params-file install/lesson06/share/lesson06/config/lesson06_parameter_node.yaml
```
