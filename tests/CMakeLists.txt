cmake_minimum_required(VERSION 3.0)

set(NAME tcp_cpp_test)

add_executable(${NAME} main.cpp tcp_cpp/library_test.h)

target_include_directories(${NAME} PRIVATE "${PROJECT_SOURCE_DIR}/include")

target_link_libraries(${NAME} tcp_cpp)