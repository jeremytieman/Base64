find_package(GTest)

if(NOT GTest_FOUND)
  add_subdirectory(external)
endif()

add_executable(base64Test main.cpp)
target_link_libraries(base64Test gtest_main base64)
target_include_directories(base64Test PRIVATE ${CMAKE_SOURCE_DIR}/inc/)
set_target_properties(base64Test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/test/)

add_test(NAME b64Test COMMAND base64Test)
