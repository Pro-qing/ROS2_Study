# 第 07 课：Service 请求与响应

本课从第三、四课的连续 topic 通信过渡到一次请求对应一次响应。使用标准 `std_srvs/srv/SetBool`，避免先引入自定义接口。

## 题目索引

### lesson07.01：topic、service 与参数

比较三者的适用场景，说明 service 的 request/response 关系与 topic 连续数据流的区别。

### lesson07.02：Service server

完成 [`lesson07_service_server.cpp`](src/lesson07_service_server.cpp)：

1. 读取 `SetBool::Request::data`。
2. 设置 `Response::success` 和 `Response::message`。
3. 保证 service 对象在 `spin` 期间存活，并用 CLI 验证。

### lesson07.03：Service client

完成 [`lesson07_service_client.cpp`](src/lesson07_service_client.cpp)：

1. 有界等待服务可用。
2. 发送请求并检查 future 返回状态。
3. 输出 response 内容，区分服务不可用、超时和成功响应。

## 验收标准

- [ ] server 和 client 均构建无新警告。
- [ ] `ros2 service list` 能看到 `/lesson07_set_enabled`。
- [ ] `ros2 service call /lesson07_set_enabled std_srvs/srv/SetBool "{data: true}"` 返回正确响应。
- [ ] client 能处理服务不可用和请求超时。

## 常用命令

```bash
source /opt/ros/jazzy/setup.bash
colcon build --symlink-install --packages-select lesson07
source install/setup.bash
ros2 run lesson07 lesson07_service_server
```

另开终端：

```bash
source /opt/ros/jazzy/setup.bash
source install/setup.bash
ros2 run lesson07 lesson07_service_client
```
