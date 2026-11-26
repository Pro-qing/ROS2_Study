from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    # TODO 1: 为这个练习选择一个节点名称或主题重映射。
    publisher = Node(
        package="lesson03",
        executable="lesson03_publisher",
        name="lesson03_publisher",
        output="screen",
        remappings=[("/lesson03_chatter", "/lesson05_chatter")],
    )
    subscriber = Node(
        package="lesson04",
        executable="lesson04_subscriber",
        name="lesson04_subscriber",
        output="screen",
        remappings=[("/lesson03_chatter", "/lesson05_chatter")],
    )

    # TODO 2: 保持发布者和订阅者的配置兼容。
    return LaunchDescription([publisher, subscriber])
