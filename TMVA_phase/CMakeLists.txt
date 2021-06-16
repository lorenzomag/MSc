cmake_minimum_required(VERSION 3.10)

project(TMVA)

find_package(ROOT COMPONENTS TMVA MLP Minuit TreePlayer TMVAGui XMLIO m)

set(SOURCES TMVAClassification_federica.C)

include(${ROOT_USE_FILE})

add_definitions(${ROOT_CXX_FLAGS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${ROOT_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR} PUBLIC ${ROOT_INCLUDE_DIRS})

