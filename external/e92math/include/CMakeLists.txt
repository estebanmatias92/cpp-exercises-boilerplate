# Set the header files list
#file(GLOB headers "${CMAKE_CURRENT_LIST_DIR}/*.hpp")

# IDEs should put the headers in a nice place
#source_group(
#    TREE ${CMAKE_CURRENT_LIST_DIR}
#    PREFIX "Header Files"
#    FILES ${headers})

install(FILES e92math.hpp DESTINATION include)