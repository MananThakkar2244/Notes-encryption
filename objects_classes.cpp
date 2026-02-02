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

void regPass::implementROT13() // This will implement and covert all 10 passwords into ROT13
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

void folder::unlockFolder()
{
    rename("Example_Notes.locked", "Example_Notes");

#ifdef _WIN32
    system("start Example_Notes");
#elif __APPLE__
    system("open Example_Notes");
#else
    system("xdg-open Example_Notes");
#endif
}

void folder::timer()
{
    sleep_for(10s);
    rename("Example_Notes", "Example_Notes.locked");
}
regPass::regPass()
{
    randomPassword();
    implementROT13();
    fileOpening();
}