# ROS 2 预备题库

本文件只保存尚未正式讲授的候选题目，不代表学习者已经学习、尝试或通过相关知识点，也不是固定课程路线。正式生成题目时，必须结合 `ROS2_LEARNING_CATALOG.md`、`ROS2_LEARNING_HANDOFF.md` 和实际审查证据动态选择。

## 使用规则

- 每次正式生成 3～5 道题，不要求每次同时包含错题、复习题和强化训练题。
- 主课使用 `lessonNN`，同一课下的题目使用连续小标，例如 `lesson05.01`、`lesson05.02`。
- 小标只表示题目顺序，题目类别由 `类型` 字段标明。
- `错题` 只能在真实错误、代码审查或验收证据出现后创建；本预备题库不虚构学习者弱点。
- 题目正式讲授、回答或审查后，才将结果写入 QA、catalog 或 handoff；预备状态不写入学习目录。
- 物理目录继续遵循 ROS package 命名约定，例如 `src/lesson04/cpp_practice/`；`lesson04.01` 只是文档和学习记录中的逻辑编号。

## lesson05：Launch 启动文件

### lesson05.01

- 类型：复习题
- 题目：说明 `ros2 run` 与 `ros2 launch` 的职责差异，并解释 launch 中 package、executable、node name 三者如何对应。
- 适用证据：已完成手动启动多个节点，但尚未学习统一启动流程。
- 状态：预备

### lesson05.02

- 类型：强化训练题
- 题目：编写一个最小 Python launch 描述，同时启动已有 publisher 和 subscriber，并说明 `generate_launch_description`、`LaunchDescription` 与 `launch_ros.actions.Node` 的作用。
- 适用证据：开始 launch 专题时，需要把已验证的第三、四课节点组合起来。
- 状态：预备

### lesson05.03

- 类型：强化训练题
- 题目：给 launch 增加一个话题重映射或节点名称配置，验证启动后的节点和话题名称，并解释配置发生在 launch 层还是节点源码层。
- 适用证据：完成最小 launch 后，需要练习可观察的配置变化。
- 状态：预备

## lesson06：参数

### lesson06.01

- 类型：复习题
- 题目：解释为什么参数应先声明再读取，并区分参数默认值、命令行覆盖值和源码中的硬编码常量。
- 适用证据：已掌握节点、定时器和话题通信，尚未验证运行时配置。
- 状态：预备

### lesson06.02

- 类型：强化训练题
- 题目：为一个节点添加类型明确的参数读取，让发布周期或消息前缀可以通过参数配置，并验证默认值与命令行覆盖值。
- 适用证据：需要把已有 timer 或 publisher 练习改造成可配置节点。
- 状态：预备

### lesson06.03

- 类型：强化训练题
- 题目：使用 YAML 参数文件启动节点，检查参数类型、参数命名空间和运行时实际值，说明参数文件与 launch 的数据流。
- 适用证据：完成单参数练习后，继续练习可复现配置。
- 状态：预备

## lesson07：Service

### lesson07.01

- 类型：复习题
- 题目：比较 topic、service 和参数的适用场景，并说明 service 的 request/response 关系与 topic 连续数据流的区别。
- 适用证据：已完成 publisher/subscriber，准备学习请求-响应通信。
- 状态：预备

### lesson07.02

- 类型：强化训练题
- 题目：创建一个标准接口 service server，完成请求回调、响应字段设置和服务对象生命周期管理，并用 CLI 验证请求结果。
- 适用证据：需要从已有 callback 经验过渡到 service 回调签名。
- 状态：预备

### lesson07.03

- 类型：强化训练题
- 题目：编写 service client，等待服务可用后异步发送请求，使用合适的 spin 或 future 等待方式取得响应，并处理服务不可用情况。
- 适用证据：完成 server 后练习客户端、future 和有界等待。
- 状态：预备

## lesson08：Action

### lesson08.01

- 类型：复习题
- 题目：比较 action、service 和 topic，说明 action 为什么适合可取消、可反馈、可能持续较长时间的任务。
- 适用证据：已掌握 service 请求-响应后，准备学习长期任务接口。
- 状态：预备

### lesson08.02

- 类型：强化训练题
- 题目：实现 action server 的 goal、cancel、feedback 和 result 流程，保持执行状态可解释，并验证取消请求的行为。
- 适用证据：需要分别理解 action 的多个生命周期回调和结果通道。
- 状态：预备

### lesson08.03

- 类型：强化训练题
- 题目：实现 action client，等待 server、发送 goal、接收 feedback 和最终 result，并说明异步回调中的对象生命周期。
- 适用证据：完成 action server 后练习客户端状态流转。
- 状态：预备

## lesson09：测试

### lesson09.01

- 类型：复习题
- 题目：区分编译验收、运行验收、ROS 图检查和自动化测试；说明它们分别能发现哪类问题。
- 适用证据：已有多次手动 build、run 和 topic/service 检查记录。
- 状态：预备

### lesson09.02

- 类型：强化训练题
- 题目：为一个不依赖 ROS 的纯 C++ 函数添加边界测试，至少覆盖正常输入、空输入和边界数值，并解释每个断言验证的契约。
- 适用证据：需要把算法或字符串处理从节点中独立出来验证。
- 状态：预备

### lesson09.03

- 类型：强化训练题
- 题目：为 ROS 2 节点增加一个最小集成测试或接口检查，验证节点启动、话题/服务存在以及关键输出，避免使用无界运行进程。
- 适用证据：已有手动联调经验，准备建立可重复的验收流程。
- 状态：预备

## lesson10：Executor 与综合复习

### lesson10.01

- 类型：复习题
- 题目：解释 `rclcpp::spin`、executor、timer 回调、subscription 回调之间的调度关系，并说明没有 spin 时会发生什么。
- 适用证据：已学习 timer、publisher 和 subscriber 的回调执行流程。
- 状态：预备

### lesson10.02

- 类型：强化训练题
- 题目：在一个需要多个回调的节点中比较单线程 executor、callback group 和多线程 executor 的职责；只在确有必要时引入并发行为。
- 适用证据：完成基础回调课程后，需要理解 executor 扩展点而不是提前引入多线程。
- 状态：预备

### lesson10.03

- 类型：强化训练题
- 题目：综合检查一个 publisher/subscriber 或 service 节点的数据流、QoS、对象生命周期、错误处理和可测试性，列出从源码到运行时接口的验收顺序。
- 适用证据：用于阶段性复习，不替代针对真实错误的错题。
- 状态：预备
