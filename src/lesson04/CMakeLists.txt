cmake_minimum_required(VERSION 3.8)
project(lesson04)

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

add_executable(lesson04_subscriber src/lesson04_subscriber.cpp)
ament_target_dependencies(lesson04_subscriber rclcpp std_msgs)

install(TARGETS
  lesson04_subscriber
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
