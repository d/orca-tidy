cmake_minimum_required(VERSION 3.4)
project(orca_tidy LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

set(SOURCE_FILES orca_tidy/RemoveCtorDtorComments.cc orca_tidy/RemoveCtorDtorComments.h orca_tidy/TidierInterface.h orca_tidy/TidierInterface.cc orca_tidy/Rewriter.cc orca_tidy/Rewriter.h)
add_library(tidy_lib OBJECT ${SOURCE_FILES})
add_executable(orca_tidy orca_tidy/main.cc $<TARGET_OBJECTS:tidy_lib>)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

enable_testing()
set(TEST_SOURCE_FILES orca_tidy/RemoveCtorDtorCommentsTest.cc)
add_executable(orca-tidy-test ${TEST_SOURCE_FILES} $<TARGET_OBJECTS:tidy_lib> )

add_subdirectory(vendor/googletest/googletest EXCLUDE_FROM_ALL)
# We use target_include_directories instead include_directories here because only
# tests should include gtest headers
target_include_directories(orca-tidy-test PRIVATE ${gtest_SOURCE_DIR}/include)

target_link_libraries(orca-tidy-test gtest_main)
