#include <iostream>
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