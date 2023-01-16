#
# Includes
#

include(CMakePrintHelpers)



#
#   Couple of helpers
#

# Macro to add automatically all subdirectories from a folder
function(get_subdirectories subdirs directory)
    # Get all sub-directories (GLOB is bad practice)
    file(GLOB items RELATIVE ${directory} LIST_DIRECTORIES true "*")
    
    set(listdir "")
    
    # Add every directory to the list
    foreach(item ${items})
        set(dirpath ${directory}/${item})
        # Add the sub-directory only if it has CMakeLists.txt file
        if(IS_DIRECTORY ${dirpath} AND EXISTS ${dirpath}/CMakeLists.txt)
            list(APPEND listdir ${item})
        endif()
    endforeach()

    set(${subdirs} ${listdir})
    set(${subdirs} ${${subdirs}} PARENT_SCOPE)
endfunction()

# Add every direct sub directory
function(add_subdirectories directory)    
    # Get sub directories
    get_subdirectories(items ${directory})
    
    # Add everyone
    foreach(item ${items})
        add_subdirectory(${item})
    endforeach()
endfunction()

## Function to parse string to PascalCase
#function(to_pascalcase parsed message)
#
#    set(new_message "")
#    string(TOLOWER ${message} message)
#
#    string(REGEX REPLACE "[^A-Za-z0-9]" ";" words "${message}")
#    foreach(word ${words})    
#        message(STATUS ${word})
#
#        string(SUBSTRING ${word} 0 1 first_letter)
#        string(TOUPPER ${first_letter} first_letter)
#        string(REGEX REPLACE "^.(.*)" "${first_letter}\\1" pascal_cased "${word}")
#        
#        list(APPEND new_message ${pascal_cased})
#    endforeach()
#
#    string(REGEX REPLACE ";" "" new_message "${new_message}")
#
#    set(${parsed} ${new_message} PARENT_SCOPE)
#endfunction()
#


# Get folder name
function(get_folder_name name)
    get_filename_component(folder_name ${CMAKE_CURRENT_LIST_DIR} NAME)

    set(${name} ${folder_name})
    set(${name} ${${name}} PARENT_SCOPE)
endfunction()