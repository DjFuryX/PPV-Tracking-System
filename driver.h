// Driver Class
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include "Date.h"
#include "Address.h"
#include "User.h"
#include "Ticket.h"
using namespace std;

#ifndef Driver_h
#define Driver_h

class Driver : public User
{
protected:
    int trn;
    int appID;//remember to change
    int driverId;
    int contactnumber;
    char name[maxStringsize];
    char denyReason[maxStringsize];
    char emailAddr[maxStringsize];
    Address currAddr;
    Date dob;

public:
    Driver()
    {
        trn = 0;
        contactnumber = 0;
        writeFixedLengthString(name, "NotSet");
        writeFixedLengthString(emailAddr, "Notset");
        writeFixedLengthString(denyReason, "NotSet");
        driverId=0;
    }

    Driver(int trn, int contactnumber, string name, string denyReason, string emailAddr, int password)
    {
        this->trn = trn;
        this->contactnumber = contactnumber;
        writeFixedLengthString(this->name, name.c_str());
        writeFixedLengthString(this->denyReason, denyReason.c_str());
        writeFixedLengthString(this->emailAddr, emailAddr.c_str());
        this->password = password;
        // currAddr.SetAdrress();
        // dob.SetDob();
    }
    /*Driver(int trn, int contactnumber,string name, string denyReason, string emailAddr)
    {
        this->trn = trn;
        this->contactnumber= contactnumber;
        //writeFixedLengthString(name);
        currAddr.SetAdrress();
    }*/

    int GetTrn()
    {
        return trn;
    }

    int GetContactNumner()
    {
        return contactnumber;
    }

    string GetName()
    {
        return name;
    }
    string GetEmailAddr()
    {
        return emailAddr;
    }

    Address GetAddress()
    {
        return currAddr;
    }

    Date GetDob()
    {
        return dob;
    }

    void setTrn()
    {

        cin >> trn;
    }

    void setName()
    {

        getInput(cin, name);
    }

    void setDob()
    {

        dob.SetDob();
    }
    void setAddress()
    {

        currAddr.SetAdrress();
    }

    void setEmailAddress()
    {

        getInput(cin, emailAddr);
    }

    void setContactNumber()
    {

        cin >> contactnumber;
    }

    void createDriver()
    {
        cout << "Please Enter Drivers TRN" << endl;
        setTrn();
        cout << "Please Enter Drivers's Full Name" << endl;
        setName();
        cout << "Please Enter Drivers's Date of Birth" << endl;
        setDob();
        cout << "Please Enter Drivers's Address" << endl;
        setAddress();
        cout << "Please Enter Drivers's Email Address" << endl;
        setEmailAddress();
        cout << "Please Enter Drivers's Contact Number" << endl;
        setContactNumber();

        saveDriver(driverId);
        driverId++;
    }

     int updateMenu()
    {
        int choice;
        // Get current date and time
        time_t timestamp;
        time(&timestamp);
        system("cls");                                 // clears the screen
        cout << "Date: " << ctime(&timestamp) << endl; // print current date and time
        /*prints a menu so the user can select their desired choice*/
        cout << "\n\t\t +--------------------------------+ Update Menu +--------------------------------+" << endl;
        cout << "\t\t | " CYN "1." RST "    Change Name                                                           |" << endl;
        cout << "\n\t\t | " CYN "2." RST "   Change TRN                                                       |" << endl;
        cout << "\n\t\t | " CYN "3." RST "   Change Address                                                        |" << endl;
        cout << "\n\t\t | " CYN "4." RST "    Change Email Address                                                        |" << endl;
        cout << "\n\t\t | " CYN "5." RST "    Change Phone Number                                                 |" << endl;
        cout << "\n\t\t | " CYN "0." RST "    Exit                                                                      |" << endl;
        cout << "\t\t +---------------------------------------------------------------------------------+" << endl;
        cout << "\nPlease select with the " CYN "digits" RST " on the left:  " << endl; // prompts for user choice
        cin >> choice;
        system("cls");
        // clears the screen
        return choice;
    }

    void updateMenuHandler()
    {
        int option = this-> updateMenu(); // get user option

        while (option != 0)
        { // Start while loop for main menu

            switch (option)
            { // case structure is used to determine option selected
            case 1:
                setName();
                break;
            case 2:
                setTrn();
                break;
            case 3:
                setAddress();
                break;
            case 4:
                setEmailAddress();
                break;
            case 5:
                setContactNumber();
            default: // if an invalid number is entered
                cout << "Invalid option chosen" << endl;
                break;
            } // end switch case
            option = this->updateMenu(); // get user option
        }
    }

    virtual void handler()
    {

        int option = this->ShowMenu(); // get user option

        while (option != 0)
        { // Start while loop for main menu

            switch (option)
            { // case structure is used to determine option selected
            case 1:
                this->createDriver();
                break;
            case 2:
               this->updateMenuHandler();
                    break;
            case 3:

                break;
            case 6:

                break;
            default: // if an invalid number is entered
                cout << "Invalid option chosen" << endl;
                break;
            } // end switch case

        
            system("pause");
            option = this->ShowMenu(); // get user option
        }
    };
    int ShowMenu()
    {
        int choice;
        // Get current date and time
        time_t timestamp;
        time(&timestamp);
        system("cls");                                 // clears the screen
        cout << "Date: " << ctime(&timestamp) << endl; // print current date and time
        /*prints a menu so the user can select their desired choice*/
        cout << "\n\t\t +--------------------------------+ Driver Menu +--------------------------------+" << endl;
        cout << "\t\t | " CYN "1." RST "    Create Driver                                                               |" << endl;
        cout << "\n\t\t | " CYN "2." RST "   Update Driver                                                              |" << endl;
        cout << "\n\t\t | " CYN "3." RST "    Delete Driver                                                             |" << endl;
        cout << "\n\t\t | " CYN "5." RST "    Check Application Status                                                  |" << endl;
        cout << "\n\t\t | " CYN "0." RST "    Exit                                                                      |" << endl;
        cout << "\t\t +---------------------------------------------------------------------------------+" << endl;
        cout << "\nPlease select with the " CYN "digits" RST " on the left:  " << endl; // prompts for user choice
        cin >> choice;
        system("cls");
        // clears the screen
        return choice;
    }

    void Login()
    {
        try
        {
            // Display Driver's login prompt
            cout << "\n\t\t +----------------------------+ Driver Login +----------------------------+\n"
                 << endl;
            cout << "\t\tPlease enter TRN:\t";
            int enteredTRN;
            cin >> enteredTRN; // Input the TRN

            cout << "\t\tPlease enter Password:\t";
            int enteredPassword;    // Password as an integer
            cin >> enteredPassword; // Input the password

            if (enteredTRN <= 0 || enteredPassword <= 0)
            {
                throw runtime_error("Invalid TRN or password. Please try again.");
                User::ShowMenu();
            }

            // Check if entered TRN and password are correct
            if (enteredTRN == trn && enteredPassword == getPassword())
            {
                cout << "Login successful! Welcome, Driver " << name << "." << endl;
                // You can add additional functionality here (e.g., viewing tickets, fines, etc.)
                system("pause");
            }
            else
            {
                cout << "Invalid TRN or password. Please try again." << endl;
                system("pause");
            }
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
            system("cls");
            this->Login();
        }
    }


    void saveDriver(int driverID)
    {
        int OFFSET=100;

        string filename="DriverList.dat";
        try
        {
            // ofstream raFile(filename, ios::binary | ios::app);
            ofstream raFile(filename, ios::binary | ios::out);
            if (raFile.fail())
            {
                throw runtime_error("cannot create database");
            }
            raFile.seekp((appID - OFFSET) * sizeof(*this));
            raFile.write(reinterpret_cast<const char *>(this), sizeof(*this));
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

};

#endif // Driver_h