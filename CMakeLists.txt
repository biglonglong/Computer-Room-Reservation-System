# Minimum CMake version required
cmake_minimum_required(VERSION 3.15)

# Ensure IDE and IO uses UTF-8
add_compile_options(/source-charset:utf-8 /execution-charset:utf-8)

# Project name
project(ComputerRoomReservationSystem)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Find all source and header files
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.h" "include/*.hpp")

# Get the absolute path of the data directory
get_filename_component(DATA_DIR "${CMAKE_SOURCE_DIR}/data" ABSOLUTE)

# Add the absolute path as a definition
add_definitions(-DDATA_DIR="${DATA_DIR}")

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Add the executable
add_executable(ComputerRoomReservationSystem ${SOURCES} ${HEADERS})