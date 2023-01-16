#pragma once
#include <string>
#include <vector>

namespace e92
{
    class Exercise
    {

    private:
        int mSelected;
        std::vector<int> mList;
        std::string mDirectory = "./src/exercises";
        std::string mMethodPrefix = "exercise_";
        std::string mFilePrefix = "exercise_";
        std::string mFileExtension = ".cpp";

        std::vector<std::string> GetFiles();                                // GetFiles
        std::vector<std::string> FilterExercises(std::vector<std::string>); // FilterExercises
        void UpdateList(std::vector<std::string>);                          // UpdateList

        bool IsValid(int);
        std::string getMethodName(); // Get exercise method's name

    public:
        Exercise(); // Constructor

        std::vector<int> getAll(); // Show list of exercises

        void Select(int); // Input option

        void Launch(); // Launch selected exercise
    };

}