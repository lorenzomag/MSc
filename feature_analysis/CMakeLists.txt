cmake_minimum_required(VERSION 3.10)

project(features)

find_package(ROOT)



set(SOURCES features.C search.C select_features.C)


include(${ROOT_USE_FILE})

add_definitions(${ROOT_CXX_FLAGS})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})

target_include_directories(${CMAKE_PROJECT_NAME} 
                            PUBLIC ${ROOT_INCLUDE_DIRS})
target_link_libraries(${CMAKE_PROJECT_NAME} ${ROOT_LIBRARIES})
target_precompile_headers(${CMAKE_PROJECT_NAME} PRIVATE pch.h)