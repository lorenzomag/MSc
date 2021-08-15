set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")

find_library(SQLITE3 sqlite3)
find_library(SQLITECPP SQLiteCpp)

# add_executable(run_TMVA classification.C)

# message("${SQLITE3}")
# message("${SQLITECPP}")

# target_link_libraries(run_TMVA 
# 	PUBLIC ${ROOT_LIBRARIES}
# 	PRIVATE ${SQLITE3} ${SQLITECPP}
# 	PRIVATE nfd)

# target_include_directories(run_TMVA 
# 	PUBLIC ../include
# 	PRIVATE $ENV{WORKSPACE_DIR}/include
# 	)
	
	
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
	
	
	add_executable(punzi_fom punzi_fom.C)
	
	target_link_libraries(punzi_fom
	PRIVATE ${SQLITE3} ${SQLITECPP}
	PUBLIC ${ROOT_LIBRARIES})
	target_include_directories(punzi_fom 
	PRIVATE $ENV{WORKSPACE_DIR}/include
	PUBLIC ../include
	)
	