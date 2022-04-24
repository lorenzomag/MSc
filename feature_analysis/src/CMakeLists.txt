cmake_minimum_required(VERSION 3.14.0)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")



find_package(ROOT REQUIRED)
include(${ROOT_USE_FILE})

add_executable(${PROJECT_NAME} main.C search.C select_features.C draw.C)
target_include_directories(${PROJECT_NAME}
                            PUBLIC ../include
                            PUBLIC "$ENV{WORKSPACE_DIR}/include"
                            )
target_link_libraries(${PROJECT_NAME} PUBLIC ${ROOT_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PUBLIC $ENV{WORKSPACE_DIR}/include/pch.h)
