cmake_minimum_required(VERSION 3.18)


project(TMVA)

find_package(ROOT COMPONENTS TMVA TMVAGui)

include(${ROOT_USE_FILE})

add_subdirectory(nfd)
add_subdirectory(src)
