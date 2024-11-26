#include <iostream>
using namespace std;

#define BCK "\x1b[1F"  // define line clear for console print
#define CYN "\x1B[36m" // define colour yellow for console print
#define YEL "\x1B[33m" // define colour yellow for console print
#define RED "\x1B[31m" // define colour red for console print
#define GRN "\x1B[32m" // define colour green for console print
#define RST "\x1B[0m"  // define colour white for console print

class User
{
private:
    string username;
    int password;

public:


    virtual int ShowMenu()
    {
        int choice;
        // Get current date and time
        time_t timestamp;
        time(&timestamp);
        system("cls");                                 // clears the screen
        cout << "Date: " << ctime(&timestamp) << endl; // print current date and time
        /*prints a menu so the user can select their desired choice*/
        cout << "\n\t\t +--------------------------------+ Please Login +--------------------------------+" << endl;
        cout << "\t\t | " CYN "1." RST "    Driver                                                                    |" << endl;
        cout << "\n\t\t | " CYN "2." RST "    JCF Officer                                                               |" << endl;
        cout << "\n\t\t | " CYN "3." RST "    Processing Officer                                                        |" << endl;
        cout << "\n\t\t | " CYN "0." RST "    Exit                                                                      |" << endl;
        cout << "\t\t +---------------------------------------------------------------------------------+" << endl;
        cout << "\nPlease select with the " CYN "digits" RST " on the left:  " << endl; // prompts for user choice
        cin >> choice;

        system("cls");
        return choice;
        // clears the screen
    }

    virtual void Login() = 0;
};
