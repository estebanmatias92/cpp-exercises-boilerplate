cmake_minimum_required(VERSION "3.18")

# Settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Get folder name
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)

# Set Project Name out of Folder's name
project(${PROJECT_NAME} LANGUAGES CXX)

# Create library
add_library(${PROJECT_NAME} INTERFACE)

# Link the include directory to the target
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_LIST_DIR})