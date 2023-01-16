# Get folder name
get_filename_component(libname ${CMAKE_CURRENT_LIST_DIR} NAME)

# Create lib Target
add_library(${libname} SHARED)

# Link the libraries for this Target
target_link_libraries(${libname}
    PUBLIC tools
           external)

# Link the include path to this target
target_include_directories(${libname} PUBLIC ${CMAKE_SOURCE_DIR}/include/${libname})

# Get all source files and link them
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC_FILES)
target_sources(${libname} PUBLIC ${SRC_FILES})

# Instructions for installing this library
install(TARGETS ${libname} RUNTIME DESTINATION lib)