

# Find ROOT and set variables
find_package(ROOT COMPONENTS TMVA TMVAGui)
include(${ROOT_USE_FILE})

set(FORT_ENABLE_TESTING OFF CACHE INTERNAL "")

add_subdirectory("$ENV{WORKSPACE_DIR}/extern/CLI11" CLI11)
add_subdirectory("$ENV{WORKSPACE_DIR}/extern/libfort" libfort)
add_subdirectory("$ENV{WORKSPACE_DIR}/extern/SQLiteCpp" SQLiteCpp)
add_subdirectory("$ENV{WORKSPACE_DIR}/extern/yaml-cpp" yaml-cpp)

add_executable(tmva tmva.C
					classification.C
					GetPunzi.C 
					DatabaseExpo.C 
					evaluation.C 
					from_sql.C 
					from_toml.C) 

set_target_properties(tmva PROPERTIES RUNTIME_OUTPUT_DIRECTORY "$ENV{WORKSPACE_DIR}/TMVA_phase/build")

target_include_directories(tmva
		PRIVATE $ENV{WORKSPACE_DIR}/include
		PUBLIC ../include)
target_link_libraries(tmva
		PRIVATE SQLiteCpp
		PRIVATE sqlite3
		PRIVATE pthread
		PRIVATE dl
		PRIVATE yaml-cpp
		PRIVATE CLI11::CLI11
		PRIVATE libfort::fort
		PRIVATE ${ROOT_LIBRARIES})

target_precompile_headers(tmva PUBLIC $ENV{WORKSPACE_DIR}/include/pch.h)
