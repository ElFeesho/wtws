cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")

add_executable (wtws_main main.cpp)
link_directories (../wtws)
include_directories (../wtws)
target_link_libraries (wtws_main wtws)
