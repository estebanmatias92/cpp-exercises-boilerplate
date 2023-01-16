cmake_minimum_required(VERSION $ENV{CMAKE_VERSION})

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set top-level Target name
project($ENV{PROJECT_NAME} LANGUAGES C CXX)

# Include custom CMake helpers
include(cmake/helpers.cmake)

# Add the modules/libs
add_subdirectory(tools)
add_subdirectory(external)
add_subdirectory(include)
add_subdirectory(src)

# Create an CMake option to build the examples for the libs
option(BUILD_EXAMPLE "Build the libraries examples" OFF)

if (BUILD_EXAMPLE)
    message(STATUS "Building examples...")
    #add_subdirectory(examples)
endif()