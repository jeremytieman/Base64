set(SOURCE_FILES Base64.cpp)
add_library(Base64 ${SOURCE_FILES})
target_include_directories(Base64 PRIVATE ${CMAKE_SOURCE_DIR}/inc/)
set_target_properties(Base64 PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/)