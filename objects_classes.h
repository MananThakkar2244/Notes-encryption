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
    std::string rgPass[10], rot13pass[10]; // The converted passwords will be stored in ROT13
    void randomPassword();
    void fileOpening();
    void implementROT13();

public:
    regPass();
    bool check_regPass(std::string pass);
};

class folder // This is a class that locks the targeted folder and unlocks it when the user-entered password is correct
{
public:
    void unlockFolder(std::string filename);
};
#endif