cmake_minimum_required(VERSION 3.8)
project(lesson02)

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

add_executable(lesson02_timer src/lesson02_timer.cpp)
ament_target_dependencies(lesson02_timer rclcpp)

install(TARGETS
  lesson02_timer
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
