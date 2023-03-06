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
    void ShowOptions(vector<void (*)()> &);

    void run()
    {
        do
        {
            system("clear"); // Clear screen

            Exercise exercise; // Initialize the exercises

            ShowTitle();
            ShowOptions(exercise.mList);

            try
            {
                int option = 0; // Input option
                cout << "Enter an option: ";
                cin >> option;
                cin.ignore();
                cout << endl;

                if (option == 0)
                    break;

                exercise.Launch(option); // Launch selected exercise
            }
            catch (const char *msg)
            {
                cerr << endl
                     << msg << " ";  // Show the error
                usleep(2 * 1000000); // Sleep for 2 seconds
                continue;            // Jump to the next iteration
            }

            // Pause flow
            cout << endl
                 << "Enter to main screen... ";
            getchar();

        } while (true);
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
    void ShowOptions(vector<void (*)()> &exercises)
    {
        int size = exercises.size();
        cout << "Exercises: [";
        for (int i = 1; i <= size; i++)
            cout << i << ((i != size) ? ", " : "]\n"); // Show each item with colons

        cout << "Exit: (0)" << endl // Show exit option
             << endl;
    }

}