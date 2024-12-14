cmake_minimum_required(VERSION 3.10)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(main main.cpp
        calc.cpp)
add_executable(tests test.cpp
        calc.cpp)