#include <iostream>
#include <cctype>
#include "objects_classes.h"
using namespace std;
int main()
{
    adminPass ap;
    string pass;
    char choice;
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
                if (ap.checkPass(pass)) // This will check the password
                {
                    cout << "Cool!!";
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