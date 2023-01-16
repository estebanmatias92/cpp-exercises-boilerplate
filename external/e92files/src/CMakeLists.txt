# Get all source files and link them
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC_FILES)
target_sources(${PROJECT_NAME} PRIVATE ${SRC_FILES})