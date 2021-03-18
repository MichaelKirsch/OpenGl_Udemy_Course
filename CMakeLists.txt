cmake_minimum_required(VERSION 3.17)
set(PROJECT_NAME OpenGl_Udemy_Course)
project(${PROJECT_NAME})


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(include/GLFW)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)


add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL GLEW::GLEW)