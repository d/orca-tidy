cmake_minimum_required(VERSION 3.5)
project(orca-tidy CXX)
add_library(tidy_lib OBJECT orca_tidy/RemoveCtorDtorComments.cc orca_tidy/RemoveCtorDtorComments.h)

add_executable(tidy
        main.cc
        $<TARGET_OBJECTS:tidy_lib>
        )
target_compile_features(tidy_lib PUBLIC cxx_constexpr)
include_directories(${CMAKE_SOURCE_DIR})

enable_testing()
add_subdirectory(vendor/googletest/googletest)
include_directories(${gtest_SOURCE_DIR}/include)
add_executable(orca_tidy_tests
        orca_tidy/RemoveCtorDotrCommentsTest.cc
        $<TARGET_OBJECTS:tidy_lib>
        )
target_link_libraries(orca_tidy_tests gtest_main)
