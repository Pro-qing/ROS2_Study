cmake_minimum_required(VERSION 3.8)
project(lesson10)

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

add_executable(lesson10_executor_demo src/lesson10_executor_demo.cpp)
ament_target_dependencies(lesson10_executor_demo rclcpp std_msgs)

install(TARGETS
  lesson10_executor_demo
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
