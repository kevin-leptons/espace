cmake_minimum_required(VERSION 3.0)
project(espace-project)

# flags
set(CMAKE_C_FLAGS "-std=gnu99 -Wall -pthread")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}")
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}")

# setup build directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# setup header files
include_directories(include)
add_subdirectory(include)

# setup implementation directory
add_subdirectory(src)
