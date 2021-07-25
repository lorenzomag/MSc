cmake_minimum_required(VERSION 3.0.0)

project(set_masses)

set(EXECUTABLE_OUTPUT_PATH "../")

add_subdirectory("$ENV{WORKSPACE_DIR}/utils/nativefiledialog-extended" "nfd")

find_package(ROOT)
include(${ROOT_USE_FILE})

add_executable(${PROJECT_NAME} set_masses.C)


target_link_libraries(${PROJECT_NAME} PRIVATE nfd ${ROOT_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE $ENV{WORKSPACE_DIR}/include)
