cmake_minimum_required(VERSION 3.10)
project(Base)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_executable(Base src/main.cpp src/ast/Node.cpp src/ast/Node.h)

add_subdirectory(lib/rapidcheck)
add_subdirectory(test)
