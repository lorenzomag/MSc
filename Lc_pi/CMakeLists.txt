cmake_minimum_required(VERSION 3.0.0)
project(resonance VERSION 0.1.0)
find_package(ROOT)

include(${ROOT_USE_FILE})

add_executable(${PROJECT_NAME} resonant_state_analysis.C)

target_link_libraries(${PROJECT_NAME} PRIVATE ${ROOT_LIBRARIES})