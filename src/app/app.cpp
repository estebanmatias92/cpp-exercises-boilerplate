#include <iostream>
#include <string>

#include <unistd.h> // For the delay
#include <stdlib.h>

#include "app.hpp"
#include "exercise.hpp"

using namespace std;
using namespace e92;

/*
    Start the app from this function
*/
namespace app
{
    void ShowTitle();
    void ShowOptions(const vector<int> &);
    int SelectOption(Exercise &);
    void LaunchExercise(Exercise &);

    void run()
    {
        bool repeat = true;

        do
        {
            system("clear"); // Clear screen

            Exercise exercise_obj; // Initialize the exercises

            ShowTitle();
            ShowOptions(exercise_obj.getAll());

            int option; // Input option
            try
            {
                cout << "Enter an option: ";
                option = SelectOption(exercise_obj);
                cout << endl;
            }
            catch (const char *msg)
            {
                cerr << endl
                     << msg << " ";  // Show the error
                usleep(2 * 1000000); // Sleep for 2 seconds
                continue;            // Jump to the next iteration
            }

            if (option == 0) // Get out if the option is zwro
            {
                repeat = false;
                break;
            }

            LaunchExercise(exercise_obj); // Launch selected exercise

            // Pause flow
            cout << endl
                 << "Enter to main screen... ";
            getchar();

        } while (repeat);
    }

    /*
        Just print the title
    */
    void ShowTitle()
    {
        cout << endl
             << endl
             << "============" << endl
             << "    MENU    " << endl
             << "============" << endl
             << endl
             << endl;
    }

    /*
        Print the options from the exercise objects available
    */
    void ShowOptions(const vector<int> &list_exercises)
    {
        int last = list_exercises.back(); // Get last exercise

        cout << "Exercises: [";
        for (const auto &i : list_exercises)
            cout << i << ((i != last) ? ", " : "]\n"); // Show each item with colons

        cout << "Exit: (0)" << endl // Show exit option
             << endl;
    }

    /*
        Take the object exercise and take user input and return the option entered
    */
    int SelectOption(Exercise &exercise)
    {
        size_t option;
        cin >> option;
        cin.ignore();

        if (option == 0)
            return option;

        exercise.Select(option);

        return option;
    }

    /*
        Take the object exercise and Launch the exercise function
    */
    void LaunchExercise(Exercise &exercise)
    {
        exercise.Launch();
    }
}