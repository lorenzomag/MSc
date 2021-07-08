set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR})

add_executable(run_TMVA TMVAClassification.C)

target_link_libraries(run_TMVA PRIVATE nfd PUBLIC ${ROOT_LIBRARIES})
target_include_directories(run_TMVA PUBLIC ../include)


add_executable(apply_TMVA TMVAClassificationApplication.C)

target_link_libraries(apply_TMVA PRIVATE nfd PUBLIC ${ROOT_LIBRARIES})
target_include_directories(apply_TMVA PUBLIC ../include)


add_executable(analyse_output exploreOutput.C)

target_link_libraries(analyse_output PRIVATE nfd PUBLIC ${ROOT_LIBRARIES})
target_include_directories(analyse_output PUBLIC ../include)
