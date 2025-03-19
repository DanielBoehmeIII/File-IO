/*
Boehme
3.12.25
CIT 245 Z01
Chapter 12 implementation of FileIO class to be used by a driver/application file
*/

#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "filestream.h"
using std::cout;
using std::cin;
using std::string;
using std::getline;


int main()
{
    using namespace filestream;

    string response;
    cout << "Please enter an existing file name or a new one: ";
    getline(cin, response);

    FileIO file;

    if (response.empty())
    {
        FileIO file;
    }
    else
    {
        FileIO file(response);
    }

    while (true)
    {
        cout << "Read or write (r/w)? ";
        getline(cin, response);  // Reuse response for input

        if (response == "r")
        {
            file.read(cout);
            cout << std::endl;
        }
        else if (response == "w")
        {
            cout << "Enter your text. Type 'END' on a new line to finish:\n";
            string data;
            string line;

            while (true)
            {
                getline(cin, line);
                if (line == "END") break;
                data += line + "\n";  // Preserve multi-line input
            }

            file.write(data);
        }
        else
        {
            cout << "Invalid option. Please enter 'r' to read or 'w' to write." << std::endl;
            continue;
        }

        cout << "Continue? (y/n)? ";
        getline(cin, response);
        if (response == "n")
        {
            break;
        } else if (response == "y") {
            continue;
        } else {
            cout << "Invalid option. Please enter 'y' to continue or 'n' to stop." << std::endl;
            break;
        }
    }

    return 0;
}
