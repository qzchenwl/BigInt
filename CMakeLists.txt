cmake_minimum_required(VERSION 2.8)

# Make PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, and PROJECT_NAME available.
set(PROJECT_NAME BigInt)
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)

add_subdirectory(${EXT_PROJECTS_DIR}/gtest-1.6.0)

include_directories(${COMMON_INCLUDES})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_library(BigInt src/BigInt.cpp)
add_executable(demo src/main.cpp)
target_link_libraries(demo BigInt)

enable_testing()

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(runUnitTests ${TEST_SRC_FILES})
target_link_libraries(runUnitTests gtest gtest_main)
target_link_libraries(runUnitTests BigInt)
add_test(NAME that-test-I-made COMMAND runUnitTests)
add_test(that-other-test-I-made runUnitTests)
