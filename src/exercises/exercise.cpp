#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <dlfcn.h>

#include "exercise.hpp"
#include "e92files.hpp"

using namespace std;
namespace fs = e92files;

// typedef function<void> ExercisePtr;
struct export_exercise
{
    void (*call)(void);
};

namespace e92
{
    Exercise::Exercise()
    {
        vector<string> files = Exercise::GetFiles();
        vector<string> filtered = Exercise::FilterExercises(files);

        if (filtered.size() > 0)
            Exercise::UpdateList(filtered);
    }

    /*
        Function that filters a vector using lambda function as predicate.
    */
    template <typename T, typename Pred>
    auto FilterCollection(const vector<T> &data, Pred predicate)
    {
        vector<T> new_data; // New vector to store the filtered data

        for (auto &&elem : data)
            if (predicate(elem))
                new_data.push_back(elem); // If the predicate is true, store the entry

        return new_data; // Return the new vector
    }

    /*
        Return all the files in this directory
    */
    vector<string> Exercise::GetFiles()
    {
        return fs::GetFilenames(mDirectory.c_str());
    }

    /*
        Filter only the exercises
    */
    vector<string> Exercise::FilterExercises(vector<string> files)
    {
        return FilterCollection(files, [](auto &name)
                                { return (name.rfind("exercise_", 0) == 0); });
    }

    /*
        Extract the numbers of the available exercises
    */
    void Exercise::UpdateList(vector<string> items)
    {
        for (const auto &entry : items)
        {
            size_t start_pos = entry.find_first_not_of(mFilePrefix);
            size_t end_pos = entry.find_last_not_of(mFileExtension);
            size_t len = (end_pos - start_pos) + 1;
            mList.push_back(stoi(entry.substr(start_pos, len)));
        }
    }

    /*
        Check if the number corresponds with an exercise option
    */
    bool Exercise::IsValid(int option)
    {
        return (find(mList.begin(), mList.end(), option) != mList.end());
    }

    /*
        Get the exercise method's name
    */
    string Exercise::getMethodName()
    {
        return (mMethodPrefix + to_string(mSelected));
    }

    /*
        Get vector with all the exercises
    */
    vector<int> Exercise::getAll()
    {
        return mList;
    }

    /*
        Input option
    */
    void Exercise::Select(int option)
    {
        if (Exercise::IsValid(option))
            mSelected = option;
        else
            throw "Incorrect option";
    }

    /*
        Launch selected exercise
    */
    void Exercise::Launch()
    {
        // Library name
        const char *libpath = (mDirectory + "/").c_str();

        // Get the file loaded
        void *libhandle = dlopen(libpath, RTLD_NOW);

        // Get the function loaded
        if (libhandle)
        {
            struct export_exercise *imports = (struct export_exercise *)dlsym(libhandle, Exercise::getMethodName().c_str());
            if (imports)
                imports->call();
        }

        // Close the file
        dlclose(libhandle);
    }

}