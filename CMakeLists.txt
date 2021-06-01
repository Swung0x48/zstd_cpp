cmake_minimum_required(VERSION 3.13)
project(zstd_cpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(includes/zstd/lib)
add_subdirectory(includes/zstd/build/cmake)
add_executable(zstd_cpp main.cpp zstdcpp.h)
target_link_libraries(zstd_cpp libzstd_static)