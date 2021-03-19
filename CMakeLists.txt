cmake_minimum_required(VERSION 3.17)
set(PROJECT_NAME OpenGl_Udemy_Course)
project(${PROJECT_NAME})


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

set(CMAKE_CXX_STANDARD 17)

include_directories(include/GLAD/include)
add_subdirectory(include/GLFW)





add_executable(${PROJECT_NAME} main.cpp include/GLAD/src/glad.c)

target_link_libraries(${PROJECT_NAME} glfw  )