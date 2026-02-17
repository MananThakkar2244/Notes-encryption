#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "objects_classes.h"

using namespace std::chrono;
using namespace std::this_thread;

bool adminPass::checkPass(std::string pass)
{
    if (pass == adPass)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool regPass::check_regPass(std::string pass)
{
    for (int i = 0; i < 10; i++)
    {
        if (pass == rgPass[i])
        {
            return true;
        }
    }
    return false;
}

void regPass::randomPassword() // This will create 10 random passwords
{
    srand(time(0));
    std::string characters = "qwertyuiopasdfghjklzxcvbnm1234567890";
    for (int i = 0; i < 10; i++)
    {
        std::string randword = "";
        for (int j = 0; j < 8; j++)
        {
            int randomindex = rand() % characters.length();
            randword += characters[randomindex];
        }
        rgPass[i] = randword;
    }
}

void regPass::fileOpening()
{
    std::ofstream myfile("passwords.txt"); // This will create a file containing all 10 encrypted passwords.
    for (int i = 0; i < 10; i++)           // Once generated it will edit the orginial file for new ones
    {
        myfile << rot13pass[i] << std::endl;
    }
    myfile.close();

#ifdef _WIN32 // This will open the passwords.txt file based on the OS this program is running on
    system("start passwords.txt");
#elif __APPLE__
    system("open passwords.txt");
#else
    system("xdg-open passwords.txt");
#endif
}

void regPass::implementROT13() // This will implement and convert all 10 passwords into ROT13
{
    char ch, temp;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < rgPass[i].length(); j++)
        {
            ch = rgPass[i][j];
            if (ch >= 'a' && ch <= 'z')
            {
                temp = ((ch - 'a' + 13) % 26) + 'a';
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                temp = ((ch - 'A' + 13) % 26) + 'A';
            }
            else
            {
                temp = ch;
            }
            rot13pass[i] += temp;
        }
    }
}

void folder::unlockFolder(std::string filename)
{
    std::string lockedExtension = ".locked";

    if (filename.length() >= lockedExtension.length() &&
        filename.substr(filename.length() - lockedExtension.length()) == lockedExtension)
    {
        std::string originalName = filename.substr(0, filename.length() - lockedExtension.length());

        if (rename(filename.c_str(), originalName.c_str()) == 0)
        {
#ifdef _WIN32
            system(("start " + originalName).c_str());
#elif __APPLE__
            system(("open " + originalName).c_str());
#else
            system(("xdg-open " + originalName).c_str());
#endif

            sleep_for(std::chrono::hours(1));

            std::string relockedName = originalName + lockedExtension;
            rename(originalName.c_str(), relockedName.c_str());
        }
    }
    else
    {
        std::string lockedName = filename + lockedExtension;
        rename(filename.c_str(), lockedName.c_str());
    }
}

regPass::regPass()
{
    randomPassword();
    implementROT13();
    fileOpening();
}