# 第 08 课：Action 长时间任务

本课在 service 请求-响应基础上学习可反馈、可取消、可能持续较长时间的 action。使用 `example_interfaces/action/Fibonacci`，暂不创建自定义 action 接口。

## 题目索引

### lesson08.01：action、service 与 topic

比较三者的通信模型，说明 action 为什么适合可取消、可反馈和持续时间较长的任务。

### lesson08.02：Action server

完成 [`lesson08_action_server.cpp`](src/lesson08_action_server.cpp)：

1. 编写 goal、cancel 和 accepted 回调。
2. 执行 Fibonacci 任务时发布 feedback。
3. 正确返回 result，并验证取消行为。

### lesson08.03：Action client

完成 [`lesson08_action_client.cpp`](src/lesson08_action_client.cpp)：

1. 有界等待 action server。
2. 发送 goal，接收 feedback 和最终 result。
3. 说明异步回调中的 goal handle、future 和消息对象生命周期。

## 验收标准

- [ ] server 和 client 构建无新警告。
- [ ] goal 能被接受并产生 feedback。
- [ ] client 能观察最终 result。
- [ ] 取消请求能产生可解释的状态和结果。

## 常用命令

```bash
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install --packages-select lesson08
source install/setup.bash
ros2 run lesson08 lesson08_action_server
```

另开终端运行 client，或使用 `ros2 action list` 检查 action 名称。
