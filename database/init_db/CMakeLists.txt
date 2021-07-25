cmake_minimum_required(VERSION 3.0.0)
project(init_db VERSION 0.1.0)

find_library(SQLITE sqlite3 REQUIRED)
find_library(SQLITECPP SQLiteCpp REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE "$ENV{WORKSPACE_DIR}/include")
target_link_libraries(${PROJECT_NAME} ${SQLITECPP} ${SQLITE} pthread dl)
