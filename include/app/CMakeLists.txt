# Set the header files list
#file(GLOB ${PROJECT_NAME}_headers "${CMAKE_CURRENT_LIST_DIR}/*.hpp")

# IDEs should put the headers in a nice place
#source_group(
#    TREE ${CMAKE_CURRENT_LIST_DIR}
#    PREFIX "Header Files"
#    FILES ${${PROJECT_NAME}_headers})

install(FILES app.hpp DESTINATION include)