cmake_minimum_required(VERSION 3.0.0)

project (decay_length_converter VERSION 1.0)


add_library(Converter converter.cpp)
target_include_directories(Converter PRIVATE ../../include)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
add_executable(converter main.cpp)

target_include_directories(converter PRIVATE ../../include)
target_link_libraries(converter Converter)
endif()