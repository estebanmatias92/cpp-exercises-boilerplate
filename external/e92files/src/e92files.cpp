#include <iostream>
#include <string>
#include <vector>
#include <dirent.h>
#include <sys/types.h>

#include "e92files.hpp"

using std::string;
using std::vector;

/*
    Funcion que toma un mensaje y lo encripta.
*/
vector<string> e92files::GetFilenames(const char *path)
{
    DIR *directory;
    struct dirent *entry;
    directory = opendir(path); // open all directory

    vector<string> filenames{};

    if (directory == NULL)
        return filenames;

    while ((entry = readdir(directory)) != NULL) // If the directory was right, iterate over the files
    {
        string filename = entry->d_name;

        if (filename.compare(".") == 0 || filename.compare("..") == 0)
            continue; // Skip if the names are parent and current relative directories symbols

        filenames.push_back(filename);
    }

    closedir(directory); // close all directory

    return filenames;
}