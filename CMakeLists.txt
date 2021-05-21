cmake_minimum_required (VERSION 3.0)
project (Base64 CXX)
set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

add_subdirectory(external)
add_subdirectory(src)

enable_testing()
add_subdirectory(test)
