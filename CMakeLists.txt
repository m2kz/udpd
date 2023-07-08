# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.27)

# Project's name
project(udpd)

find_library(LIBMAGIC magic)
if (NOT LIBMAGIC)
    message(FATAL_ERROR "libmagic not found")
endif()

find_program(CLANG_TIDY_EXECUTABLE NAMES clang-tidy)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/conan/conan_toolchain.cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(CLANG_TIDY_EXECUTABLE)
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXECUTABLE}")
else()
    message(FATAL_ERROR "clang-tidy not found")
endif()
# Set the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER "/usr/bin/g++-11")
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_CLANG_TIDY clang-tidy -checks=-*,readability-*)

# Add executable target with source files
add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE "include")
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS} ${LIBMAGIC})