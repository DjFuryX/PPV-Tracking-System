// Process_Officer Class
#include "User.h"

class ProcessOfficer : public User
{
private:
    int officerId;
    string name;
    string asssignedStation;

public:
    ProcessOfficer()
    {
        officerId = 100;
        name = "ProcessOfficer";
        asssignedStation = "NoAssignedStation";
    }
    ProcessOfficer(int id, string officerName, string stationName)
    {
        officerId = id;
        name = officerName;
        asssignedStation = stationName;
    }

    void Login()
    {
        string username;
        int password;

        cout << "Please enter Username" << endl;
        cin>>username;
        cout<<"Please enter Password"<<endl;
        cin>>password;
    }

    int ShowMenu(){

         int choice;
        // Get current date and time
        time_t timestamp;
        time(&timestamp);
        system("cls");                                 // clears the screen
        cout << "Date: " << ctime(&timestamp) << endl; // print current date and time
        /*prints a menu so the user can select their desired choice*/
        cout << "\n\t\t +--------------------------------+ Process Officer Menu +--------------------------------+" << endl;
        cout << "\t\t | " CYN "1." RST "    Applicant                                                                    |" << endl;
        cout << "\n\t\t | " CYN "2." RST "    Driver                                                               |" << endl;
        cout << "\n\t\t | " CYN "0." RST "    Exit                                                                      |" << endl;
        cout << "\t\t +---------------------------------------------------------------------------------+" << endl;
        cout << "\nPlease select with the " CYN "digits" RST " on the left:  " << endl; // prompts for user choice
        cin >> choice;

        system("cls");
        return choice;
        // clears the screen

    }
};