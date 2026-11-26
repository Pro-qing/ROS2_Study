# ROS 2 学习问答与理解验收记录

本文件保存思考题、理解验收问题、学习者回答和教练反馈。练习要求与可执行验收标准见各课 EXERCISE.md；构建和运行证据摘要见学习目录与交接文档。

## 记录约定

- 历史题号使用 `LNN-QNN`，课内连续编号；思考题与理解验收题共用编号，不随措辞修订而改变。新课程题目和子练习使用 `lessonNN.MM` 逻辑编号，例如 `lesson05.01`；逻辑编号不改写已有 package 路径。
- 每题记录类型、问题、学习者回答、教练反馈和状态（待回答／待复核／通过）。需要修改答案时保留原答，另记补充回答。
- 不把教练示例或纠正内容写成学习者原答；未观察到的回答标为“未记录”，不推断通过。
- 运行验收是检查项，不是每项都要新增问答；需要口头解释的项目关联题号。历史课程不追补虚构问答。
- 本次迁移日期：2026-10-18。原有回答保留原措辞；题目按原练习或对话整理。

## 第 01～02 课

无单独留存的学习者问答。保留原有课程完成结论，不新增待回答题目或推断历史回答。

## 第 03 课：发布话题消息

### L03-Q01

- 类型：思考题
- 问题：为什么晚启动的 ros2 topic echo 不一定能看到 count = 0？
- 状态：通过（此前审查，迁移于 2026-10-18）

学习者原答：

```text
ans.1: 晚启动的 `ros2 topic echo` 不一定看到 `count = 0`
    关键在发布者的 `QoS`:
    `rclcpp::QoS(rclcpp::KeepLast(10)).reliable().durability_volatile()`
    其中的 `durability_volatile()` 表示： 发布者不会给晚加入的订阅者补发它加入之前已经发布过的消息。
```

教练反馈：正确，volatile 不向晚加入者补发旧消息。

### L03-Q02

- 类型：思考题／生命周期理解验收
- 问题：为什么回调中的 count 引用在本程序运行期间有效？
- 状态：通过（此前审查，迁移于 2026-10-18）

学习者原答：

```text
ans.2: 回调中的 `count` 引用有效，
    因为 `count` 是 `main` 函数里的局部变量：
    `std::size_t count = 0;`
    它的生命周期从定义开始，一直到 `main` 返回才结束。
    `lambda` 捕获的是：
    `[publisher, &count]() {...}`
    `&count` 是引用捕获，不拥有对象，只是引用 `main` 栈帧里的那个 `count`。而定时器回调由：
    `rclcpp::spin(node);` 驱动。 `spin(node)` 就在 `main` 里面阻塞运行，所有 `timer` 回调都发生在 `spin` 返回之前，也就是 `main` 返回之前。
    所以回调执行时：
    `main` 的栈帧仍然存在；
    `count` 仍然活着；
    `&count` 仍然指向有效对象。
    当 `rclcpp::shutdown()` 使 `spin` 返回后，不会再触发 `timer` 回调；随后 main 返回，局部变量才销毁。因此本程序里这个引用是安全的。
```

教练反馈：核心解释正确。通常 Ctrl+C 的默认信号处理触发 shutdown，使 spin 返回；main 末尾再调用 shutdown。本课没有其它执行器线程继续调度回调。

### L03-Q03

- 类型：理解验收
- 问题：为什么保留 timer 智能指针？销毁它会怎样？(void)timer 是否影响生命周期？
- 状态：通过（2026-10-18）

学习者原答：

```text
ans3:如果创建定时器后立即销毁 `timer` 智能指针，为什么不能继续期待回调触发？第 29 行的 `(void)timer`; 是否影响生命周期？
    定时器对象必须活着，回调才可能被触发。 `create_wall_timer` 返回的是 `rclcpp::TimerBase::SharedPtr`，这个 `shared_ptr` 是定时器的主要所有权。如果它被销毁（例如离开作用域或 `reset()`），定时器对象析构，会从 `executor / callback group` 中注销，之后 `spin` 不会再触发它的回调。
    第 29 行的 `(void)timer`; 不影响生命周期。 它只是把 `timer` 表达式转成 `void`，告诉编译器“我故意不使用这个变量”，用于消除 `unused variable` 警告。它既不会延长也不会缩短 `timer` 的生命周期。
```

教练反馈：生命周期和 (void)timer 的核心理解正确。精确来说，最后一个共享所有者释放后对象才析构；create_wall_timer 返回具体 WallTimer<回调类型>::SharedPtr，可转换为 TimerBase::SharedPtr。无需将对象析构理解为必须显式执行某个“注销”调用。

### L03-Q04

- 类型：原练习理解验收项
- 问题：说明消息 data 字段、publish 和本题 QoS 的作用。
- 学习者回答：未单独记录；volatile 部分见 L03-Q01。
- 教练反馈：历史记录未逐项保存解释，不补造回答；第三课原有完成结论保持不变。
- 状态：待回答（补充记录，不追溯阻塞已完成课程）

## 第 04 课：话题订阅回调

### L04-Q01

- 类型：思考题
- 问题：为什么订阅节点不需要自己的 timer？
- 状态：通过（2026-10-18）

### L04-Q02

- 类型：思考题／理解验收
- 问题：省略 spin，即使保留 subscription，会执行消息回调吗？
- 状态：通过（2026-10-18）

L04-Q01、L04-Q02 学习者原答（保留合并书写）：

```text
ans:
  1.订阅节点不需要自己的 timer， 是因为采用回调的形式去运行的，当发布者的数据到达订阅者的时候，相应的函数会自动执行，而不是需要定时器去触发对应的动作。
  2.如果省略 spin ，即使保留 subscription ,仍旧不会执行消息回调，因为create_subscription只是注册这个回调，舍弃spin后，程序不会去执行这个函数。

```

教练反馈：两个思考题回答正确。“自动执行”精确指消息到达后，由 spin 中的执行器调度回调；create_subscription 本身只创建订阅并注册回调。

### L04-Q03

- 类型：理解验收
- 问题：ConstSharedPtr 限制的是消息还是指针？
- 状态：通过（2026-10-18）

学习者原答（文件与对话）：

```text
  1.ConstSharedPtr 限制的是「消息」，不是「指针」;
  std_msgs::msg::String::ConstSharedPtr 是消息类型内部定义的一个别名，本质是：
  using ConstSharedPtr = std::shared_ptr<const std_msgs::msg::String>;
```

教练反馈：正确；它是 shared_ptr<const Message>。不能通过它修改消息，指针变量本身仍可重新赋值或 reset。

### L04-Q04

- 类型：理解验收
- 问题：[logger] 为什么不依赖局部 logger 的引用？
- 状态：通过（2026-10-18）

学习者原答（文件与对话）：

```text
  2.因为 [logger] 是按值捕获，lambda 内部持有的是 logger 的一个拷贝，不是 main 中那个局部变量的引用。
```

教练反馈：正确，lambda 保存日志器副本。

### L04-Q05

- 类型：原练习理解验收项
- 问题：为什么 subscription 必须在 spin 期间保持存活？
- 学习者回答：未单独记录。
- 教练反馈：代码正确保留 subscription；未保存单独口头解释，不把代码证据当作原答。
- 状态：待回答（补充记录，不追溯阻塞已完成课程）

## lesson05：Launch 启动文件

本轮开始学习 Launch。题目来自预备题库；当前没有新的错误证据，因此不创建错题。逻辑编号使用 `lesson05.MM`，与历史 `LNN-QNN` 编号并行保留。

### lesson05.01

- 类型：复习题
- 问题：说明 `ros2 run` 与 `ros2 launch` 的职责差异，并解释 launch 中 package、executable、node name 三者如何对应。
- 学习者回答：未记录。
- 教练反馈：待学习者回答后记录；重点检查是否区分“启动一个已安装可执行文件”和“按描述统一启动、配置多个节点”。
- 状态：待回答

### lesson05.02

- 类型：强化训练题
- 问题：编写一个最小 Python launch 描述，同时启动已有的 `lesson03_publisher` 和 `lesson04_subscriber`，并说明 `generate_launch_description`、`LaunchDescription` 与 `launch_ros.actions.Node` 各自的作用。要求给出文件路径、两个 Node 配置的关键字段，以及启动命令。
- 学习者回答：未记录。
- 教练反馈：待学习者提交 launch 文件或伪代码后记录；重点检查两个节点的 package、executable、name 配置和 launch 描述返回值。
- 状态：待回答

### lesson05.03

- 类型：强化训练题
- 问题：在 lesson05.02 的 launch 基础上增加一个话题重映射或节点名称配置，说明该配置发生在 launch 层还是节点源码层，并列出至少两条可观察的验收命令来验证配置确实生效。
- 学习者回答：未记录。
- 教练反馈：待学习者提交配置和验收步骤后记录；重点检查是否能区分 launch 配置、ROS 图名称和源码内硬编码名称。
- 状态：待回答

## lesson06：参数

### lesson06.01

- 类型：复习题
- 问题：解释为什么参数应先声明再读取，并区分参数默认值、命令行覆盖值和源码中的硬编码常量。
- 学习者回答：未记录。
- 教练反馈：待回答后记录；重点检查参数声明、读取和覆盖的顺序与职责。
- 状态：待回答

### lesson06.02

- 类型：强化训练题
- 问题：完成 `src/lesson06/src/lesson06_parameter_node.cpp`，让 `message_prefix` 和 `period_ms` 通过类型明确的参数控制节点行为，并验证默认值与命令行覆盖值。
- 学习者回答：未记录。
- 教练反馈：待提交代码和运行证据后记录；重点检查参数类型、timer 周期和日志前缀是否来自参数。
- 状态：待回答

### lesson06.03

- 类型：强化训练题
- 问题：使用 `src/lesson06/config/lesson06_parameter_node.yaml` 启动节点，检查参数类型、参数命名和运行时实际值，并说明 YAML 参数文件与节点之间的数据流。
- 学习者回答：未记录。
- 教练反馈：待提交命令和观察结果后记录；重点检查参数文件路径、节点名和实际覆盖效果。
- 状态：待回答

## lesson07：Service 请求与响应

### lesson07.01

- 类型：复习题
- 问题：比较 topic、service 和参数的适用场景，并说明 service 的 request/response 关系与 topic 连续数据流的区别。
- 学习者回答：未记录。
- 教练反馈：待回答后记录；重点检查是否能按通信模式和时序选择接口。
- 状态：待回答

### lesson07.02

- 类型：强化训练题
- 问题：完成 `src/lesson07/src/lesson07_service_server.cpp`，使用 `std_srvs/srv/SetBool` 读取请求、设置响应，并保持 service 对象在 spin 期间存活。
- 学习者回答：未记录。
- 教练反馈：待提交代码和 CLI 验证后记录；重点检查回调签名、响应字段和 service 生命周期。
- 状态：待回答

### lesson07.03

- 类型：强化训练题
- 问题：完成 `src/lesson07/src/lesson07_service_client.cpp`，有界等待服务可用，异步发送请求并处理成功、超时和服务不可用情况。
- 学习者回答：未记录。
- 教练反馈：待提交代码和运行证据后记录；重点检查 future 状态和进程退出行为。
- 状态：待回答

## lesson08：Action 长时间任务

### lesson08.01

- 类型：复习题
- 问题：比较 action、service 和 topic，说明 action 为什么适合可取消、可反馈、可能持续较长时间的任务。
- 学习者回答：未记录。
- 教练反馈：待回答后记录；重点检查 goal、feedback、result 和 cancel 的职责区分。
- 状态：待回答

### lesson08.02

- 类型：强化训练题
- 问题：完成 `src/lesson08/src/lesson08_action_server.cpp`，实现 goal、cancel、feedback 和 result 流程，并验证取消请求的行为。
- 学习者回答：未记录。
- 教练反馈：待提交代码和 action CLI/客户端证据后记录；重点检查 goal handle 生命周期和终态处理。
- 状态：待回答

### lesson08.03

- 类型：强化训练题
- 问题：完成 `src/lesson08/src/lesson08_action_client.cpp`，等待 server、发送 goal、接收 feedback 和最终 result，并解释异步回调中的对象生命周期。
- 学习者回答：未记录。
- 教练反馈：待提交代码和运行证据后记录；重点检查回调选项、future 和 client 生命周期。
- 状态：待回答

## lesson09：测试与验收

### lesson09.01

- 类型：复习题
- 问题：区分编译验收、运行验收、ROS 图检查和自动化测试，并说明它们分别能发现哪类问题。
- 学习者回答：未记录。
- 教练反馈：待回答后记录；重点检查验收层次与证据边界。
- 状态：待回答

### lesson09.02

- 类型：强化训练题
- 问题：完成 `src/lesson09/src/lesson09_logic.cpp` 和测试，为纯 C++ 函数覆盖正常输入、零值和较大边界值，并解释每个断言验证的契约。
- 学习者回答：未记录。
- 教练反馈：待提交测试结果后记录；重点检查测试是否独立于 ROS，失败时是否能定位到函数契约。
- 状态：待回答

### lesson09.03

- 类型：强化训练题
- 问题：根据 `src/lesson09/test/lesson09_interface_check.md` 编写有界的 ROS 节点启动和接口检查，验证节点、话题或服务存在以及关键输出。
- 学习者回答：未记录。
- 教练反馈：待提交脚本或命令和结果后记录；重点检查超时、清理和环境失败区分。
- 状态：待回答

## lesson10：Executor 与综合复习

### lesson10.01

- 类型：复习题
- 问题：解释 `rclcpp::spin`、executor、timer 回调、subscription 回调之间的调度关系，并说明没有 spin 时会发生什么。
- 学习者回答：未记录。
- 教练反馈：待回答后记录；重点检查 spin 的调度作用与回调注册的区别。
- 状态：待回答

### lesson10.02

- 类型：强化训练题
- 问题：结合 `src/lesson10/src/lesson10_executor_demo.cpp`，比较单线程 executor、callback group 和多线程 executor 的职责；只在存在具体并发需求时引入多线程行为。
- 学习者回答：未记录。
- 教练反馈：待提交解释或实验结果后记录；重点检查是否把 executor、callback group 和线程混为同一概念。
- 状态：待回答

### lesson10.03

- 类型：强化训练题
- 问题：综合检查一个 publisher/subscriber 或 service 节点的数据流、QoS、对象生命周期、错误处理和可测试性，列出从源码到运行时接口的验收顺序。
- 学习者回答：未记录。
- 教练反馈：待提交验收顺序和证据后记录；重点检查是否覆盖源码、构建、运行、接口和测试边界。
- 状态：待回答
