#include <iostream>
#include <ctime>
#include <string>
#include "objects_classes.h"

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

void regPass::randomPassword()
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

regPass::regPass()
{
    randomPassword();
}