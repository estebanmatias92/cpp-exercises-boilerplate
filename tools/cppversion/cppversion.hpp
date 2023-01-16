#include <iostream>
#include <string>

using std::string;

namespace e92tools
{
    string GetCppVersion();
}

/*
    Return a string with the CPP Standard used by the compiler
*/
string e92tools::GetCppVersion()
{
    string version = "";

    switch (__cplusplus)
    {
    case 201703L:
        version = "C++17";
        break;
    case 201402L:
        version = "C++14";
        break;
    case 201103L:
        version = "C++11";
        break;
    case 199711L:
        version = "C++98";
        break;

    default:
        version = "pre-standard C++";
        break;
    }

    return version;
}