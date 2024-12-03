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

int OFFSET = 100;
const int MaxDriverRecord = 500;
const string driverFilename = "DriverList.dat";
int numDriverSaved = 0;

class Driver : public User
{
protected:
    int trn;
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
        driverId = 100;
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
        // dob.setDate();
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

    void setDate()
    {

        dob.setDate();
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
        // add check for duplicate driver
        cout << "Please Enter Drivers's Full Name" << endl;
        setName();
        cout << "Please Enter Drivers's Date of Birth" << endl;
        setDate();
        cout << "Please Enter Drivers's Address" << endl;
        setAddress();
        cout << "Please Enter Drivers's Email Address" << endl;
        setEmailAddress();
        cout << "Please Enter Drivers's Contact Number" << endl;
        setContactNumber();

        // set login credentials
        writeFixedLengthString(username, name);
        password = trn;

        driverId += numDriverSaved;
        saveDriver(driverId);
        numDriverSaved++;
    }

    virtual void Display()
    {
        cout << "Driver's Id: " << driverId << endl;
        cout << "Driver's TRN: " << trn << endl;
        cout << "Driver's Name: " << name << endl;
        cout << "Driver's Email Address: " << emailAddr << endl;
        cout << "Driver's Contact Number: " << contactnumber << endl;
        cout << "Driver's Date of Birth: " << endl;
        dob.Display();
        cout << "Driver's Address" << endl;
        currAddr.Display();
        cout << "------------------" << endl;
    }

    void showAllDrivers()
    {
        try
        {
            ifstream raFile(driverFilename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot retrieve record");
            }
            cout << "Drivers Saved: " << numDriverSaved << endl;
            for (int index = 0; index < numDriverSaved; index++)
            {

                raFile.seekg((index) * sizeof(*this));
                raFile.read(reinterpret_cast<char *>(this), sizeof(*this));
                Driver::Display();
            }
            if (raFile)
            {
                cout << "all characters read successfully." << endl;
            }
            else
            {
                cout << "error: only " << raFile.gcount() << " could be read" << endl;
            }
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
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
        cout << "\n\t\t +------------------------+ Update Menu +---------------------+" << endl;
        cout << "  \t\t | " CYN "1." RST "  Change Name                                            |" << endl;
        cout << "\n\t\t | " CYN "2." RST "  Change TRN                                             |" << endl;
        cout << "\n\t\t | " CYN "3." RST "  Change Address                                         |" << endl;
        cout << "\n\t\t | " CYN "4." RST "  Change Email Address                                   |" << endl;
        cout << "\n\t\t | " CYN "5." RST "  Change Phone Number                                    |" << endl;
        cout << "\n\t\t | " CYN "6." RST "  Change Date of Birth                                   |" << endl;
        cout << "\n\t\t | " CYN "0." RST "  Exit                                                   |" << endl;
        cout << "\t\t +------------------------------------------------------------+" << endl;
        cout << "\nPlease select with the " CYN "digits" RST " on the left:  " << endl;
 // prompts for user choice
        cin >> choice;
        system("cls");
        // clears the screen
        return choice;
    }

    void updateDriver()
    {
        int Userinput;

        cout << "Enter the drivers Tax Registration Number: " << endl;
        cin >> Userinput;

        int id = findTrn(Userinput);

        if (id == -1)
        {

            cout << "User not Found" << endl;
        }
        else
        {
            cout << "User Found" << endl;
            retrieveDriver(id);
            updateMenuHandler();
        }
    }

    void updateMenuHandler()
    {
        int option = this->updateMenu(); // get user option

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
                break;
            case 6:
                setDate();
                break;
            default: // if an invalid number is entered
                cout << "Invalid option chosen" << endl;
                break;
            } // end switch case
            option = this->updateMenu(); // get user option
        }
        saveDriver(driverId);
    }

    virtual void handler()
    {

        int option = this->ShowMenu(); // get user option

        while (option != 0)
        { // Start while loop for main menu

            switch (option)
            { // case structure is used to determine option selected
            case 1:
                
                break;
            case 2:
          
                break;
            case 3:
          
                break;
            case 4:
                break;
            case 5:
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
        cout << "\n\t\t +------------------------------+ Driver Menu +-----------------------------+" << endl;
        cout << "\n\t\t | " CYN "1." RST "    View All Tickets                                                   |" << endl;
        cout << "\n\t\t | " CYN "2." RST "    View  Tickets past-due                                             |" << endl;
        cout << "\n\t\t | " CYN "3." RST "    View  Tickets not-due                                              |" << endl;
        cout << "\n\t\t | " CYN "4." RST "    Check Warrant Status                                               |" << endl;
        cout << "\n\t\t | " CYN "5." RST "    Make Payment                                                       |" << endl;
        cout << "\n\t\t | " CYN "0." RST "    Exit                                                               |" << endl;
        cout << "\t\t +--------------------------------------------------------------------------+" << endl;
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
                Driver::Login();
            }

            // Check if entered TRN and password are correct
            if (enteredTRN == trn && enteredPassword == getPassword())
            {
                cout << "Login successful! Welcome, Driver " << name << "." << endl;
                Driver::handler();
                
                // You can add additional functionality here (e.g., viewing tickets, fines, etc.)

            }
            else
            {
                cout << "Invalid TRN or password. Please try again." << endl;
 
            }
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
            system("cls");
            this->Login();
        }
    }

    int findTrn(int searchQuery)
    {
        int foundIndex = -1;

        try
        {
            ifstream file(driverFilename, ios::in | ios::binary);
            if (file.fail())
            {
                throw runtime_error("No files to search for");
            }
            for (int i = 0; i < MaxDriverRecord; i++)
            {
                file.seekg(i * sizeof(*this));
                file.read(reinterpret_cast<char *>(this), sizeof(*this));
                if (this->trn == searchQuery)
                {
                    foundIndex = driverId;
                    break;
                }
            }
            file.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
        return foundIndex;
    }

    void saveDriver(int driverID)
    {

        try
        {
            ofstream raFile(driverFilename, ios::binary | ios::app);
            if (raFile.fail())
            {
                throw runtime_error("cannot create database");
            }
            raFile.seekp((driverID - OFFSET) * sizeof(*this));
            raFile.write(reinterpret_cast<const char *>(this), sizeof(*this));
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    void deleteDriver()
    {
        int Userinput;
        cout << "Enter the Drivers Tax Registration Number: " << endl;
        cin >> Userinput;

        int key = findTrn(Userinput);

        Driver record;
        bool was_removed = false;                     // was at least one record removed
        ifstream fin(driverFilename, ios::binary);    // open file in binary mode for reading
        ofstream fout("tmp_record.dat", ios::binary); // create temporary file to write records that should not be deleted to it, and then replace files
        while (fin.read((char *)&record, sizeof(Driver)))
        {
            if (record.driverId != key)
            {                                                      // if the record does not match
                fout.write((const char *)&record, sizeof(Driver)); // write the value to the temporary file
            }
            else
            {
                was_removed = true; // the record was removed
            }
        }
        if (!was_removed)
        {                                                                 // if nothing was deleted
            cout << "No records with key '" << key << "' found." << endl; // inform the user
        }
        else
        {
            cout << "Records with key '" << key << "' have been deleted." << endl; // inform the user of successful deletion
        }
        fin.close();                                      // close the input file
        fout.close();                                     // close the output file
        remove(driverFilename.c_str());                   // delete the old main file
        rename("tmp_record.dat", driverFilename.c_str()); // rename the temporary file to the main one
    }

    void retrieveDriver(int driverId)
    {
        try
        {
            fstream raFile(driverFilename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot retrieve record");
            }

            raFile.seekg((driverId - OFFSET) * sizeof(*this));
            raFile.read(reinterpret_cast<char *>(this), sizeof(*this));

            if (raFile)
            {
                cout << "all characters read successfully." << endl;
            }
            else
            {
                cout << "error: only " << raFile.gcount() << " could be read" << endl;
            }
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    virtual void initialiseList()
    {
        try
        {
            ifstream raFile(driverFilename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot read database");
            }
            else
            {
                Driver a1;

                for (int idx = 0; idx < MaxDriverRecord; idx++)
                {
                    raFile.seekg((idx) * sizeof(a1));
                    raFile.read(reinterpret_cast<char *>(&a1), sizeof(a1));

                    if (a1.trn != 0)
                    {
                        numDriverSaved++;
                    }
                    a1.trn = 0;
                }

                cout << "Number of drivers in system: " << numDriverSaved << endl;
                raFile.close();
            }
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
            createBlankRecords();
        }
    }

    void createBlankRecords()
    {
        try
        {
            ofstream raFile(driverFilename, ios::out | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("database cannot be created ");
                for (int idx = 0; idx < MaxDriverRecord; idx++)
                {
                    raFile.seekp((idx) * sizeof(*this));
                    raFile.write(reinterpret_cast<const char *>(this), sizeof(*this));
                }
            }
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }
};

#endif // Driver_h
