#ifndef OBJECTS_CLASSES_H
#define OBJECTS_CLASSES_H

#include <string>

class adminPass
{
private:
    std::string adPass = "ADMIN_PASSWORD";

public:
    bool checkPass(std::string pass);
};
#endif