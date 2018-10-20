cmake_minimum_required(VERSION 3.10)
project(Test)

set(CMAKE_CXX_STANDARD 17)

add_executable(Test main.cpp typechecking/TypeInfererTest.cpp typechecking/TypeInfererTest.h)
include_directories(../src)

target_link_libraries(Test BaseLibrary)
target_link_libraries(Test rapidcheck)
