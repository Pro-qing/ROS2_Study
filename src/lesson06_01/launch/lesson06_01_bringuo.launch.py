from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import PathJoinSubstitution
from launch_ros.substitutions import FindPackageShare

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="lesson06_01",
            executable="lesson06_01_parameter_node",
            name="lesson06_01_parameter_node",
            output="screen",
            parameters=[
                PathJoinSubstitution([
                    FindPackageShare("lesson06_01"),
                    "config",
                    "lesson06_01_parameter_node.yaml"
                ])
            ],
        )
    ])