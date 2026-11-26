cmake_minimum_required(VERSION 3.8)
project(lesson07)

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
find_package(std_srvs REQUIRED)

add_executable(lesson07_service_server src/lesson07_service_server.cpp)
ament_target_dependencies(lesson07_service_server rclcpp std_srvs)

add_executable(lesson07_service_client src/lesson07_service_client.cpp)
ament_target_dependencies(lesson07_service_client rclcpp std_srvs)

install(TARGETS
  lesson07_service_server
  lesson07_service_client
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
