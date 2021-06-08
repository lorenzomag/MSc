cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(converter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(HEADER_DIR ../include)

set(SOURCES converter.cpp ${HEADER_DIR}/converter.hpp)

add_executable(converter ${SOURCES})


target_include_directories(converter PRIVATE ${HEADER_DIR})