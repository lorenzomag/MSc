cmake_minimum_required(VERSION 3.0.0)

project(set_masses)

find_package(ROOT)
include(${ROOT_USE_FILE})


add_subdirectory($ENV{WORKSPACE_DIR}/extern/nativefiledialog-extended nfd)

add_executable(${PROJECT_NAME} set_masses.C)

target_link_libraries(${PROJECT_NAME} PRIVATE nfd ${ROOT_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE $ENV{WORKSPACE_DIR}/include)