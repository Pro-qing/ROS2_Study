# 第 05 课：Launch 启动文件

本课建立在第三、四课已经完成的 publisher 和 subscriber 之上，把两个节点从手动分别启动改为统一启动。当前文件是题目框架，源码中的 TODO 需要学习者完成。

## 题目索引

### lesson05.01：理解 `ros2 run` 与 `ros2 launch`

说明两条命令的职责差异，并解释 launch 中 package、executable、node name 的对应关系。

这是理解题，不要求修改源码。回答记录在 [QA](../../ROS2_LEARNING_QA.md#lesson05launch-启动文件) 中。

### lesson05.02：同时启动 publisher 和 subscriber

完成 [`lesson05_bringup.launch.py`](launch/lesson05_bringup.launch.py)：

1. 检查两个 `Node` action 的 package、executable、name 和 output。
2. 确认 `generate_launch_description()` 返回包含两个 action 的 `LaunchDescription`。
3. 使用 `ros2 launch lesson05 lesson05_bringup.launch.py` 启动第三、四课节点。

### lesson05.03：增加 launch 层配置

完成 [`lesson05_configured.launch.py`](launch/lesson05_configured.launch.py)：

1. 增加一个节点名称配置或对 `/lesson03_chatter` 的一致重映射。
2. 验证节点列表、话题列表和接收日志。
3. 说明配置发生在 launch 层还是节点源码层。

## 验收标准

- [ ] `lesson05` package 能构建并安装两个 launch 文件。
- [ ] `lesson05_bringup.launch.py` 能启动 publisher 和 subscriber。
- [ ] 配置版 launch 的节点名或话题重映射实际生效。
- [ ] 能解释 `generate_launch_description`、`LaunchDescription` 和 `Node` 的作用。

## 常用命令

```bash
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install --packages-select lesson03 lesson04 lesson05
source install/setup.bash
ros2 launch lesson05 lesson05_bringup.launch.py
```

另开终端检查：

```bash
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ros2 node list
ros2 topic list
ros2 topic info /lesson03_chatter --verbose
```
