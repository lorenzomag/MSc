cmake_minimum_required(VERSION 3.10)

project(features)

find_package(ROOT)

set(SOURCES src/features.C src/search.C src/search.h)

include(${ROOT_USE_FILE})

add_definitions(${ROOT_CXX_FLAGS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${ROOT_LIBRARIES})
target_include_directories(${PROJECT_NAME} 
                            PUBLIC ${CMAKE_SOURCE_DIR} 
                            PUBLIC ${ROOT_INCLUDE_DIRS})

