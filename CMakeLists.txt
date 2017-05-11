cmake_minimum_required(VERSION 3.3)
project(orca_tidy CXX)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 14)
set(LIB_SOURCE_FILES
orca_tidy/rewriter.cc
orca_tidy/rewriter.h
orca_tidy/writer.cc
orca_tidy/writer.h
orca_tidy/temp_file_writer.cc
orca_tidy/temp_file_writer.h
orca_tidy/ctor_comment_remover.cc
orca_tidy/ctor_comment_remover.h
orca_tidy/string_writer.cc
orca_tidy/string_writer.h
)

set(TEST_SOURCES
orca_tidy/ctor_comment_remover_test.cc
)
add_library(tidy ${LIB_SOURCE_FILES})
add_subdirectory(vendor/re2 EXCLUDE_FROM_ALL)
target_include_directories(tidy PUBLIC .)
# TODO: fix re2
target_include_directories(tidy PRIVATE ${RE2_SOURCE_DIR})
target_link_libraries(tidy re2)

add_executable(tidy_test ${TEST_SOURCES})
add_subdirectory(vendor/googletest EXCLUDE_FROM_ALL)
target_link_libraries(tidy_test tidy gtest_main)
add_executable(orca-tidy orca_tidy/main.cc)
target_link_libraries(orca-tidy tidy)
