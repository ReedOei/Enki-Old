cmake_minimum_required(VERSION 3.10)
project(Test)

set(CMAKE_CXX_STANDARD 17)

#add_library(Catch INTERFACE)
#target_include_directories(Catch ${CMAKE_BINARY_DIR}/catch)

add_executable(Test main.cpp typechecking/TypeInfererTest.cpp typechecking/TypeInfererTest.h)
include_directories(../src)
include_directories(../catch/src)
include_directories(../lib/rapidcheck/extras/catch/include/rapidcheck)
include_directories(../lib/rapidcheck/extras/catch/include)

include(CTest)

target_link_libraries(Test BaseLibrary rapidcheck)

set(CTEST_OUTPUT_ON_FAILURE 1)

add_test(NAME main_tests COMMAND Test)
add_test(NAME memory_tests COMMAND valgrind --leak-check=full $<TARGET_FILE:Test>)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
