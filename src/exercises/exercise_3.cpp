#include <iostream>
#include <string>

using namespace std;

struct export_exercise
{
    void (*call)(void);
};
struct export_exercise exercise_3 = {
    []()
    {
        cout << "I am exercise 3" << endl;
    }};