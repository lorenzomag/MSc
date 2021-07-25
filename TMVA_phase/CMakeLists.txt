cmake_minimum_required(VERSION 3.18)


project(TMVA)

find_package(ROOT COMPONENTS TMVA TMVAGui)

include(${ROOT_USE_FILE})

add_subdirectory("$ENV{WORKSPACE_DIR}/utils/nativefiledialog-extended" "nfd")
add_subdirectory(src)
