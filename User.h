#include <iostream>
#include <string>
#include<time.h>
#include"Auxillary.h"
using namespace std;



class User
{
private:
    char username[50];
    int password;

public:
    string getUserName()
    {
        return username;
    }

    int getPassword()
    {
        return password;
    }

    void setPassword(istream &stream)
    {
       cin>>password;
    }

    void setUserName(istream &stream)
    {
        getInput(cin,username);
    }

    int ShowMenu()
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
