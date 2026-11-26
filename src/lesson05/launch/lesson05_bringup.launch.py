from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    # TODO 1: verify the package, executable, name, and output fields.
    # TODO 1: 验证 package、executable、name 和 output 字段。
    publisher = Node(
        package="lesson03",
        executable="lesson03_publisher",
        name="lesson03_publisher",
        output="screen",
    )
    subscriber = Node(
        package="lesson04",
        executable="lesson04_subscriber",
        name="lesson04_subscriber",
        output="screen",
    )

    # TODO 2: return both actions in one LaunchDescription.
    # TODO 2: 在一个 LaunchDescription 中返回两个动作。
    return LaunchDescription([publisher, subscriber])
