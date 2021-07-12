cmake_minimum_required(VERSION 3.0.0)
project(prog_opts)
find_package(Boost REQUIRED program_options)

add_library(settings_selection settings_selection.cpp)
target_include_directories(settings_selection PUBLIC ../../include)
target_link_libraries(settings_selection PRIVATE ${Boost_LIBRARIES})
set_target_properties(settings_selection PROPERTIES PUBLIC_HEADER settings_selection.hpp)
install(TARGETS settings_selection 
        PUBLIC_HEADER DESTINATION "utils/include"
        ARCHIVE DESTINATION "utils/libs"
        LIBRARY DESTINATION "utils/libs")


if( CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
project(select_options)
add_executable(select_options main.cpp)
target_include_directories(select_options PRIVATE ../../include)
target_link_libraries(select_options settings_selection)

endif()
