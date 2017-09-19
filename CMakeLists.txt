cmake_minimum_required(VERSION 3.0)
project(espace-project)

# flags
set(CMAKE_C_FLAGS "-std=gnu99 -Wall -pthread")

# define
add_definitions(-D_FILE_OFFSET_BITS=64)

# setup build directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# setup header files
include_directories(include)
add_subdirectory(include)

# setup sub directory
add_subdirectory(src)
