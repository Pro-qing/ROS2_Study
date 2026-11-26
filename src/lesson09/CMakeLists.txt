cmake_minimum_required(VERSION 3.8)
project(lesson09)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_gtest REQUIRED)

add_library(lesson09_logic src/lesson09_logic.cpp)
target_include_directories(lesson09_logic PUBLIC src)

ament_add_gtest(test_lesson09_logic test/test_lesson09_logic.cpp)
target_link_libraries(test_lesson09_logic lesson09_logic)

install(TARGETS lesson09_logic
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

ament_package()
