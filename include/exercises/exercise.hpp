#pragma once
#include <string>
#include <vector>

void exercise_1();
void exercise_2();
void exercise_3();

namespace e92
{
    class Exercise
    {

    public:
        std::vector<void (*)()> mList = {
            *exercise_1, *exercise_2, *exercise_3};

        void Launch(int); // Launch selected exercise
    };

}