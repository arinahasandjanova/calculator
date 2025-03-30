cmake_minimum_required(VERSION 3.10)
project(calculator)

set(CMAKE_CXX_STANDARD 17)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
add_library(calc_lib calc.cpp)
target_include_directories(calc_lib PUBLIC ${CMAKE_SOURCE_DIR})

add_executable(calculator main.cpp)
add_executable(tests test.cpp)

target_link_libraries(calculator PRIVATE calc_lib)
target_link_libraries(tests PRIVATE calc_lib)
