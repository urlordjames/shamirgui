cmake_minimum_required(VERSION 3.10)

add_executable(shamirtest shamirtest.cpp)

target_link_libraries(shamirtest PRIVATE shamirlib gmp GTest::GTest)
target_include_directories(shamirtest PRIVATE ../shamirlib)
gtest_discover_tests(shamirtest)
