set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")

add_executable(run_TMVA TMVAClassification.C)

target_link_libraries(run_TMVA 
	PUBLIC ${ROOT_LIBRARIES}
	PRIVATE nfd)
target_include_directories(run_TMVA 
	PUBLIC ../include
	PRIVATE $ENV{WORKSPACE_DIR}/include
	)
	
	
# add_executable(apply_TMVA TMVAClassificationApplication.C)
	
# target_link_libraries(apply_TMVA 
# 	PUBLIC ${ROOT_LIBRARIES}
# 	PRIVATE nfd)
# target_include_directories(apply_TMVA 
# 	PUBLIC ../include
# 	PRIVATE $ENV{WORKSPACE_DIR}/include
# 	)
	
	
# add_executable(analyse_output exploreOutput.C)

# target_link_libraries(analyse_output 
# 	PUBLIC ${ROOT_LIBRARIES}
# 	PRIVATE nfd)
# target_include_directories(analyse_output 
# 	PUBLIC ../include
# 	PRIVATE $ENV{WORKSPACE_DIR}/include
# 	)


# add_executable(punzi_fom punzi_fom.C)
	
# target_link_libraries(punzi_fom 
# 	PUBLIC ${ROOT_LIBRARIES})
# target_include_directories(punzi_fom 
# 	PUBLIC ../include
# 	)
