set(SOURCES main.C search.C select_features.C draw.C)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES})


target_include_directories(${CMAKE_PROJECT_NAME} 
                            PUBLIC ../include
                            )

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC ${ROOT_LIBRARIES})
target_precompile_headers(${CMAKE_PROJECT_NAME} PUBLIC ../include/pch.h)