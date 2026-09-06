cmake_minimum_required(VERSION 3.8)
project(lesson01)

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

add_executable(lesson01_logger src/lesson01_logger.cpp)
ament_target_dependencies(lesson01_logger rclcpp)

install(TARGETS
  lesson01_logger
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
