cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(base64 VERSION 0.0.1 LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

  include(CTest)

endif()

add_subdirectory(src)

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME) AND BUILD_TESTING)

  add_subdirectory(test)

endif()
