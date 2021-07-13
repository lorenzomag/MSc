cmake_minimum_required(VERSION 3.10)

project(analyse_features)

find_package(ROOT)
find_library(USER_SETTINGS settings_selection REQUIRED)

include(${ROOT_USE_FILE})

add_subdirectory(src)