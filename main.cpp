#include <iostream>
#include <cctype>
#include "objects_classes.h"
using namespace std;
int main()
{
    adminPass ap;
    string pass;
    folder f;
    char choice, q;
    do
    {
        cout << "Are you an ADMIN??";
        cout << "\nEnter your choice (y = yes, n = no): ";
        cin >> choice;
        choice = tolower(choice);
        if (choice == 'y')
        {
            for (int i = 0; i < 3; i++)
            {
                cout << "Enter the password: ";
                cin >> pass;
                if (ap.checkPass(pass)) // This will check the admin password
                {
                    f.unlockFolder();
                    break;
                }
                else
                {
                    cout << "Try Again\n";
                }
            }
        }
        else if (choice == 'n')
        {
            regPass rp;
            for (int i = 0; i < 3; i++)
            {
                cout << "Enter the password: ";
                cin >> pass;
                if (rp.check_regPass(pass)) // This will check the password
                {
                    f.unlockFolder();
                    f.timer();
                    break;
                }
                else
                {
                    cout << "Try Again\n";
                }
            }
        }
    } while (choice != 'y' && choice != 'n');
    return 0;
}