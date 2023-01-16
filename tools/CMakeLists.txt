# Get the name for the library
set(libname "tools")

# Set current library name and type
add_library(${libname} INTERFACE)

# Add every subdirectory that has a CMakeLists.txt file
add_subdirectories(${CMAKE_CURRENT_LIST_DIR})

# Get all subdirs names
get_subdirectories(LIB_NAMES ${CMAKE_CURRENT_LIST_DIR})
# Link library names to current target
target_link_libraries(${libname} INTERFACE ${LIB_NAMES})