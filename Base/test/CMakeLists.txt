cmake_minimum_required(VERSION 3.10)
project(Test)

set(CMAKE_CXX_STANDARD 17)

add_executable(Test main.cpp)

target_link_libraries(Test rapidcheck)
