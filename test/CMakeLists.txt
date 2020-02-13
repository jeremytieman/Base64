add_executable(Base64Test Main.cpp)
target_link_libraries(Base64Test gtest_main Base64)
target_include_directories(Base64Test PRIVATE ${CMAKE_SOURCE_DIR}/inc/)
set_target_properties(Base64Test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/test/)

add_test(NAME B64Test COMMAND Base64Test)