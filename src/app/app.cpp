#include <iostream>
#include <string>

#include "app.hpp"
#include "e92math.hpp"
#include "cppversion.hpp"

using namespace std;
using e92math::CaesarCipher;
using e92tools::GetCppVersion;

/*
    Start the app from this function
*/
namespace app
{
    void run()
    {
        cout << endl
             << "Version: " << GetCppVersion() << endl;

        string msg = "Hello World!!!";
        cout << endl
             << "Message: " << msg << endl;

        cout << endl
             << "Upper case Caesar cipher: " << CaesarCipher(msg) << endl
             << endl;
    }
}
