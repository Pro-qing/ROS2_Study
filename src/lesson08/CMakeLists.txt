cmake_minimum_required(VERSION 3.8)
project(lesson08)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)

add_executable(lesson08_action_server src/lesson08_action_server.cpp)
ament_target_dependencies(lesson08_action_server example_interfaces rclcpp rclcpp_action)

add_executable(lesson08_action_client src/lesson08_action_client.cpp)
ament_target_dependencies(lesson08_action_client example_interfaces rclcpp rclcpp_action)

install(TARGETS
  lesson08_action_server
  lesson08_action_client
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
