// ProcessOfficer Class
#include "User.h"
#include "Applicant.h"
// #include "Driver.h"

#ifndef ProcessOfficer_H
#define ProcessOfficer_H

string msg;

class ProcessOfficer : public User
{
private:
    int officerId;
    string officerName;
    string asssignedStation;

public:
    ProcessOfficer()
    {
        officerId = 100;
        officerName = "ProcessOfficer";
        asssignedStation = "NoAssignedStation";
    }

    ProcessOfficer(int id, string name, string stationName)
    {
        officerId = id;
        officerName = name;
        asssignedStation = stationName;
    }

    void Login()
    {

        cout << "Name: " << officerName << endl;
        cout << "Password: " << officerId << endl;
        cout << "\n\t\t +--------------------------------+ Process Officer Login +--------------------------------+\n"
             << endl;
        cout << "\t\t" << msg << endl;
        cout << "\t\tPlease enter Username:\t";
        setUserName(cin);
        cout << "\t\tPlease enter Password\t";
        setPassword(cin);

        if (officerName.compare(getUserName()) == 0 && getPassword() == officerId)
        {

            cout << "Login successful" << endl;
            this->processOfficerHandler();
            system("pause");
        }
    }

    void processOfficerHandler()
    {
       

        int option = this->ShowMenu(); // get user option

        while (option != 0)
        { // Start while loop for main menu

            switch (option)
            { // case structure is used to determine option selected
            case 1:
                Applicant *currFunction = new Applicant();// test for errors
                currFunction->handler();
                break;
            case 2:
                driverHandler();
                break;

            default: // if an invalid number is entered
                cout << "Invalid option chosen" << endl;
                break;
            } // end switch case
            option = this->ShowMenu(); // get user option
        }
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
        cout << "\n\t\t +--------------------------------+ Process Officer Menu +--------------------------------+" << endl;
        cout << "\t\t | " CYN "1." RST "    Applicant                                                              |" << endl;
        cout << "\n\t\t | " CYN "2." RST "    Driver                                                               |" << endl;
        cout << "\n\t\t | " CYN "0." RST "    Exit                                                                 |" << endl;
        cout << "\t\t +---------------------------------------------------------------------------------+" << endl;
        cout << "\nPlease select with the " CYN "digits" RST " on the left:  " << endl; // prompts for user choice
        cin >> choice;
        system("cls");
        return choice;
        // clears the screen
    }


    int ShowdriverMenu()
    {
        int choice;
        // Get current date and time
        time_t timestamp;
        time(&timestamp);
        system("cls");                                 // clears the screen
        cout << "Date: " << ctime(&timestamp) << endl; // print current date and time
        /*prints a menu so the user can select their desired choice*/
        cout << "\n\t\t +--------------------------------+ Driver Menu +--------------------------------+" << endl;
        cout << "\t\t | " CYN "1." RST "    Create Driver                                                                |" << endl;
        cout << "\n\t\t | " CYN "2." RST "   Update Driver                                                               |" << endl;
        cout << "\n\t\t | " CYN "3." RST "    Delete Driver                                                              |" << endl;
        cout << "\n\t\t | " CYN "4." RST "    View All Tickets                                                           |" << endl;
        cout << "\n\t\t | " CYN "5." RST "    View  Tickets past-due                                                     |" << endl;
        cout << "\n\t\t | " CYN "6." RST "    View  Tickets not-due                                                      |" << endl;
        cout << "\n\t\t | " CYN "7." RST "    Check Warrant Status                                                       |" << endl;
        cout << "\n\t\t | " CYN "8." RST "    Make Payment                                                               |" << endl;
        cout << "\n\t\t | " CYN "9." RST "    Show All Drivers                                                           |" << endl;
        cout << "\n\t\t | " CYN "0." RST "    Exit                                                                       |" << endl;
        cout << "\t\t +---------------------------------------------------------------------------------+" << endl;
        cout << "\nPlease select with the " CYN "digits" RST " on the left:  " << endl; // prompts for user choice
        cin >> choice;
        system("cls");
        // clears the screen
        return choice;
    }


    void driverHandler()
    {
        Driver *currFunction = new Driver();

        int option = this->ShowdriverMenu(); // get user option


        while (option != 0)
        { // Start while loop for main menu

            switch (option)
            { // case structure is used to determine option selected
            case 1:
                currFunction->createDriver();
                break;
            case 2:
                currFunction->updateDriver();
                break;
            case 3:
                currFunction->deleteDriver();
                break;
            case 4:
                break;
            case 5:
                break;

            case 6:
                break;

            case 9:

                currFunction->showAllDrivers();

                break;
            default: // if an invalid number is entered
                cout << "Invalid option chosen" << endl;
                break;
            } // end switch case

            system("pause");
            option = this->ShowdriverMenu(); // get user option
        }
    };
   

    void  initialiseList(){};
};

#endif
