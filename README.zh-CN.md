# ROS 2 Jazzy C++ 学习工作区

这是一个以 **ROS 2 Jazzy、C++17、`rclcpp` 和 `ament_cmake`** 为主线的动手学习工作区。每一课聚焦一个主要 ROS 2 概念，提供可编译的代码骨架和 TODO，由学习者先完成，再进行构建、运行和代码审查。

## 环境要求

在学习主机上准备：

- Linux 环境
- ROS 2 Jazzy
- `colcon`
- C++17 编译器和 CMake
- Python 3，以及 ROS 2 构建工具需要的 `catkin_pkg`
- Codex，以及可用的 `$CODEX_HOME` 或 `$HOME/.codex`

ROS 2 的安装目录不要求固定。不同主机可以使用不同的安装路径，但目标发行版应优先保持为 Jazzy。

## 安装学习 skill

在仓库根目录执行：

```bash
./scripts/install_ros2_learning_skill.sh
```

脚本会把仓库内的 skill 安装到：

```text
$CODEX_HOME/skills/ros2-learning-coach
```

如果没有设置 `CODEX_HOME`，则使用 `$HOME/.codex/skills/ros2-learning-coach`。更新仓库后再次执行安装脚本即可同步 skill，不会修改 shell 配置或安装系统依赖。

验证安装：

```bash
test -f "${CODEX_HOME:-$HOME/.codex}/skills/ros2-learning-coach/SKILL.md"
```

## 开始学习

在 Codex 中从当前工作区发出类似请求：

```text
使用 ros2-learning-coach 继续我的 ROS 2 Jazzy C++ 学习。
```

学习 skill 会依次：

1. 定位当前工作区并读取 `ROS2_LEARNING_HANDOFF.md`。
2. 检查当前主机的 ROS 2、`colcon`、Python 和 `catkin_pkg` 环境。
3. 根据当前课程状态安排一个小练习。
4. 先提供题目、要求和代码骨架，不提前提供完整答案。
5. 等待学习者完成后，构建相关 package、运行节点并检查 ROS 2 接口。
6. 用中文指出构建错误、运行错误、C++ 问题和 ROS 2 语义问题。

当前课程位于 `src/lesson02`。完成代码后，可以请求：

```text
检查第二课
```

## 手动构建和运行

先在当前主机找到 ROS 2 setup 文件，然后从仓库根目录执行：

```bash
source /path/to/ros/setup.bash
colcon build --symlink-install --packages-select lesson02
source install/setup.bash
ros2 run lesson02 lesson02_timer
```

将 `/path/to/ros/setup.bash` 替换成当前主机实际路径。课程文档不会假定固定的用户目录或 ROS 安装目录。

如果构建提示缺少 `catkin_pkg`，先检查当前 Python：

```bash
command -v python3
python3 -c 'import catkin_pkg; print(catkin_pkg.__file__)'
```

确认可用的 Python 后，可以只在本次构建中指定它，不需要修改系统配置：

```bash
colcon build --symlink-install --packages-select lesson02 \
  --cmake-clean-cache \
  --cmake-args -DPython3_EXECUTABLE="$(command -v python3)"
```

## 学习文件说明

- `ROS2_LEARNING_HANDOFF.md`：跨主机共享的学习进度、偏好和路线。
- `src/lessonNN/EXERCISE.md`：课程目标、要求、运行方法和验收标准。
- `src/lessonNN/src/`：课程 C++ 源码。
- `skill/ros2-learning-coach/SKILL.md`：Codex 实际加载的英文 skill 源文件。
- `skill/ros2-learning-coach/SKILL.zh-CN.md`：英文 skill 的中文翻译，仅供阅读和维护。
- `scripts/install_ros2_learning_skill.sh`：把仓库内 skill 安装到当前主机的 Codex skill 目录。

`build/`、`install/` 和 `log/` 是 colcon 生成目录，不应手动编辑，也不会提交到 Git。

## C++ 学习主线

课程默认使用清晰、可维护的现代 C++，逐步练习函数与作用域、`const` 和引用、类与构造函数、RAII、智能指针、lambda、`std::chrono`、容器、错误处理和测试。

ROS 2 方面会逐步学习节点与日志、定时器、publisher、subscriber、QoS、参数、service、action、launch、executor、callback group 和综合项目。每次只引入一个主要概念，并要求同时理解对应的 C++ 所有权、回调和生命周期。
