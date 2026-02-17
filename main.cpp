#include <iostream>
#include <cctype>
#include "objects_classes.h"
using namespace std;
int main()
{
    adminPass ap;
    string pass;
    folder f;
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

                if (ap.checkPass(pass))
                {
                    int noteChoice;
                    cout << "1. ASC QB\n";
                    cout << "2. MATH QB\n";
                    cout << "3. CON QB\n";
                    cout << "4. WSD QB\n";
                    cout << "5. CPP QB\n";
                    cout << "Enter your choice: ";
                    cin >> noteChoice;

                    string filename;

                    switch (noteChoice)
                    {
                    case 1:
                        filename = "ASC_QB.pdf.locked";
                        break;
                    case 2:
                        filename = "MATH_QB.pdf.locked";
                        break;
                    case 3:
                        filename = "CON_QB.pdf.locked";
                        break;
                    case 4:
                        filename = "WSD_QB.pdf.locked";
                        break;
                    case 5:
                        filename = "CPP_QB.pdf.locked";
                        break;
                    default:
                        return 0;
                    }

                    f.unlockFolder(filename);
                    break;
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

                if (rp.check_regPass(pass))
                {
                    int noteChoice;
                    cout << "1. ASC QB\n";
                    cout << "2. MATH QB\n";
                    cout << "3. CON QB\n";
                    cout << "4. WSD QB\n";
                    cout << "5. CPP QB\n";
                    cout << "Enter your choice: ";
                    cin >> noteChoice;

                    string filename;

                    switch (noteChoice)
                    {
                    case 1:
                        filename = "ASC_QB.pdf.locked";
                        break;
                    case 2:
                        filename = "MATH_QB.pdf.locked";
                        break;
                    case 3:
                        filename = "CON_QB.pdf.locked";
                        break;
                    case 4:
                        filename = "WSD_QB.pdf.locked";
                        break;
                    case 5:
                        filename = "CPP_QB.pdf.locked";
                        break;
                    default:
                        return 0;
                    }

                    f.unlockFolder(filename);
                    break;
                }
            }
        }

    } while (choice != 'y' && choice != 'n');

    return 0;
}
