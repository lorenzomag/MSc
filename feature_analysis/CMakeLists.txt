cmake_minimum_required(VERSION 3.10)

project(analyse_features)

find_package(ROOT)

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${ROOT_USE_FILE})

add_subdirectory(src)
