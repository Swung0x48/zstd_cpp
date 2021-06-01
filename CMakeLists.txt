cmake_minimum_required(VERSION 3.16)
project(zstd_cpp)

set(CMAKE_CXX_STANDARD 20)

include_directories(includes/zstd/lib)
add_executable(zstd_cpp main.cpp zstdcpp.h)
target_link_libraries(zstd_cpp ${CMAKE_SOURCE_DIR}/includes/zstd/build/cmake/lib/libzstd.a)