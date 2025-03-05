cmake_minimum_required(VERSION 3.10)
project(pipex C)

set(CMAKE_C_STANDARD 99)

# Explicitly tell the compiler where to find headers - note the ABSOLUTE path
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add source files
file(GLOB SOURCES "src/*.c")

# Create executable
add_executable(pipex ${SOURCES})
