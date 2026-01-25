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

class regPass
{
private:
    std::string rgPass[10];
    void randomPassword();

public:
    regPass();
    bool check_regPass(std::string pass);
};
#endif