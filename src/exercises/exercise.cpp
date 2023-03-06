#include <iostream>
#include <vector>

#include "exercise.hpp"

using namespace std;

namespace e92
{
    /*
      Launch selected exercise
    */
    void Exercise::Launch(int option)
    {
        //
        mList[option - 1]();
    }
}