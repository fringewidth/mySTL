cmake_minimum_required(VERSION 3.22.1)
project(mySTL)
set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/include)

add_executable(mySTL main.cpp)
add_executable(dynamic_array_tests tests/dynamic_array_tests.cpp)

target_link_libraries(dynamic_array_tests cppunit)

