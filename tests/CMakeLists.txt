project (Test)
set(CMAKE_CXX_FLAGS "-std=c++14 ${CMAKE_CXX_FLAGS}")
enable_testing()
add_subdirectory (lib/gtest-1.7.0)

include_directories (${wtws_SOURCE_DIR})
include_directories (${gtest_SOURCE_DIR} ${gtest_SOURCE_DIR}/include) 
add_executable(wtws_tests test.cpp) 

add_test(Test wtws_tests)
target_link_libraries(wtws_tests gtest gtest_main wtws)
