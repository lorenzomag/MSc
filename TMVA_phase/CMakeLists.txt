cmake_minimum_required(VERSION 3.10)

project(TMVA)

find_package(ROOT COMPONENTS TMVA TMVAGui)

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${ROOT_USE_FILE})

add_subdirectory(nativefiledialog-extended)
add_subdirectory(src)
