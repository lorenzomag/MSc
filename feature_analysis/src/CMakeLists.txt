set(SOURCES main.C search.C select_features.C draw.C)

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")

add_executable(${PROJECT_NAME} ${SOURCES})


target_include_directories(${PROJECT_NAME} 
                            PUBLIC ../include
                            PUBLIC "$ENV{WORKSPACE_DIR}/include"
                            )
target_link_libraries(${PROJECT_NAME} PUBLIC ${ROOT_LIBRARIES}
                    # PRIVATE ${Boost_LIBRARIES} 
                    # PUBLIC settings_selection
                    )
target_precompile_headers(${PROJECT_NAME} PUBLIC ../include/pch.h)

