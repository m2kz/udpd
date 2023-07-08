# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.27)

# Project's name
project(udpd_tests)

find_library(LIBMAGIC magic)
if (NOT LIBMAGIC)
    message(FATAL_ERROR "libmagic not found")
endif()

find_program(CLANG_TIDY_EXECUTABLE NAMES clang-tidy)

if(CLANG_TIDY_EXECUTABLE)
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXECUTABLE}")
else()
    message(FATAL_ERROR "clang-tidy not found")
endif()
find_package(GTest)

set(CMAKE_TOOLCHAIN_FILE ${PROJECT_SOURCE_DIR}/../conan/build/conan_toolchain.cmake)
# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "/usr/bin/g++-11")
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,readability-*)

include_directories(${PROJECT_SOURCE_DIR}/../include)
# Add executable target with source files
ADD_EXECUTABLE(${PROJECT_NAME} sanity_check.cpp zip_test.cpp)

target_link_libraries(${PROJECT_NAME} ${LIBMAGIC})
target_link_libraries(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES})