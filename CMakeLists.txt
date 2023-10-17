cmake_minimum_required(VERSION 3.26)
project(Project C)

set(CMAKE_C_STANDARD 11)

add_library(library library.c) #To Create a library

add_executable(main main.c) # To create an executable

target_link_libraries(main library) #Link the executable with the library