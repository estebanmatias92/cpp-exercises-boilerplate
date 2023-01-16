#!/bin/sh

# App's executable
executable="${buildpath}/src/${PROJECT_NAME}"

# Log the directories
echo "Build path: '${buildpath}'"
echo "Executable path: '${executable}'"

echo "Sourcing the script functions..."

# Simply run the exe (function keyword is optional)
run() {
    ${executable}
}

# Make the directory for the build and build the project
build() {
    ./build.sh
}

# Remove the build directory
clean() {
    rm -rf ${buildpath}
    [ ! -d ${buildpath} ] && 
        echo "Build directory '${buildpath}' removed successfully." ||
        echo "'${buildpath}' directory could not be removed."
}

# Destroy and re-build everything
rebuild() {
    clean; ./build.sh
}

echo "Successfully sourced all the functions."