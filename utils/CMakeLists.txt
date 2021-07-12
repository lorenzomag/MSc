cmake_minimum_required(VERSION 3.0.0)

project(testing_stuff)


add_subdirectory(settings_selection)
add_executable(mm main.C)

target_link_libraries(mm PRIVATE program_opts)
target_include_directories(mm PUBLIC include)
