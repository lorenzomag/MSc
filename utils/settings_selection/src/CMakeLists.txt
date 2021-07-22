cmake_minimum_required(VERSION 3.18)

project(settings_selection)

IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET(CMAKE_INSTALL_PREFIX "$ENV{WORKSPACE_DIR}" CACHE PATH "Prefix of directories for installing libraries and header files" FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)



find_package(Boost REQUIRED program_options)
add_library(${PROJECT_NAME} settings_selection.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${Boost_LIBRARIES})

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER settings_selection.hpp)
install(TARGETS ${PROJECT_NAME} 
        PUBLIC_HEADER DESTINATION "include"
        ARCHIVE DESTINATION "lib"
        LIBRARY DESTINATION "lib")