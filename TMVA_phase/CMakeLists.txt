cmake_minimum_required(VERSION 3.18)

if(DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      CACHE STRING "")
endif()

project(TMVA)

find_package(ROOT COMPONENTS TMVA TMVAGui)

#set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${ROOT_USE_FILE})

add_subdirectory(nativefiledialog-extended)
add_subdirectory(src)