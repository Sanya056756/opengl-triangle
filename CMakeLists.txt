cmake_minimum_required(VERSION 3.28)
project(opengl)

set(CMAKE_CXX_STANDARD 11)
set(BUILD_SHARED_LIBS ON)

find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE GL GLEW::glew glfw)
