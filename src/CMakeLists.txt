set(SOURCE_FILES base64.cpp)
add_library(base64 ${SOURCE_FILES})

target_include_directories(base64 PRIVATE ${CMAKE_SOURCE_DIR}/inc/)
target_compile_features(base64 PRIVATE cxx_range_for)
set_target_properties(base64 PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/)
