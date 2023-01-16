#SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
#set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# Creating executable Target
add_executable(${PROJECT_NAME} main.cpp)

# Add every subdirectory that has a CMakeLists.txt file
add_subdirectories(${CMAKE_CURRENT_LIST_DIR})

# Get all subdirs names
get_subdirectories(LIB_NAMES ${CMAKE_CURRENT_LIST_DIR})
# Link library names to current target
target_link_libraries(${PROJECT_NAME} PUBLIC ${LIB_NAMES})

# Instructions for installing this executable
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
#set_target_properties(${PROJET_NAME} PROPERTIES INSTALL_RPATH_USE_LINK_PATH TRUE)
