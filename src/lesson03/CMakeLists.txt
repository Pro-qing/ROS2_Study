cmake_minimum_required(VERSION 3.8)
project(lesson03)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(lesson03_publisher src/lesson03_publisher.cpp)
ament_target_dependencies(lesson03_publisher rclcpp std_msgs)

install(TARGETS
  lesson03_publisher
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
