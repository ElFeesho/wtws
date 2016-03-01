set(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")

add_library (wtws wtws/webserver.cpp wtws/webserver.h)

