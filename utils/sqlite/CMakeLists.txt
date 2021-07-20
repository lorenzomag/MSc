cmake_minimum_required(VERSION 3.0.0)

project(sqlite VERSION 0.1.0)

IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET(CMAKE_INSTALL_PREFIX "$ENV{WORKSPACE_DIR}" CACHE PATH "Prefix of directories for installing libraries and header files" FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  
add_library(${PROJECT_NAME} sqlite3.c singleton_db.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "sqlite3.h;singleton_db.hpp")
target_compile_options(${PROJECT_NAME} PRIVATE -DSQLITE_ENABLE_JSON1)

install(TARGETS ${PROJECT_NAME} 
PUBLIC_HEADER DESTINATION "include"
ARCHIVE DESTINATION "lib"
LIBRARY DESTINATION "lib")
