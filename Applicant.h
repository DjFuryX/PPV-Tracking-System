// Applicant Class
#include <string>
#include <iostream>
#include <fstream>
#include "Driver.h"
#include "Auxillary.h"
#include "Address.h"
#include "Date.h"
using namespace std;

#ifndef Applicant_H
#define Applicant_H

//variables for random access file
const int MaxAppRecord = 500;
const string appFilename = "ApplicationList.dat";
int numApplicationSaved = 0;

class Applicant : public Driver
{

private:
    char status[maxStringsize];//status of application
    int appID;  //application id
    //booleans for applicant qualification
    bool recentAccident;   
    bool policeRecord;      
    bool ticketOutstanding;

public:
    //default constructor
    Applicant()
    {
        appID = 100;
        trn = 0;
        contactnumber = 0;
        writeFixedLengthString(name, "NotSet");
        writeFixedLengthString(emailAddr, "Notset");
        writeFixedLengthString(denyReason, "NotSet");
        writeFixedLengthString(status, "NotSet");
        recentAccident=false;
        policeRecord=false;
        ticketOutstanding=false;
    }

    //Getter for application ID
    int getappID()
    {
        return appID;
    }

    //Function to handle yes no input and logic for applicant qualification for ppv license
    bool setQualification(istream &stream)
    {
        string userInput;
        try
        {
            stream >> userInput;

            for (auto &x : userInput)
            {
                x = tolower(x);
            }
            if (userInput != "y" && userInput != "n")
            {

                throw runtime_error("Invalid input Please try again");
            }
        }
        catch (runtime_error &e)
        {
            cout << e.what() << endl;
            setQualification(cin);
        }

        return (userInput.compare("y") == 0) ? true : false;
    }


    //method to create a new application from user input
    void CreateApplication()
    {   
        //create a ticket pointer
        Ticket *ticket = new Ticket();
        //prompt for user input and save results
        cout << "Please Enter Applicants TRN" << endl;
        setTrn();
        cout << "Please Enter Applicant's Full Name" << endl;
        setName();
        cout << "Please Enter Applicant's Date of Birth" << endl;
        setDate();
        cout << "Please Enter Applicant's Contact Number" << endl;
        setContactNumber();
        cout << "Please Enter Applicant's Address" << endl;
        setAddress();
        cout << "Please Enter Applicant's Email Address" << endl;
        setEmailAddress();
        cout << "Did the driver cause any accident(s) within the last two years?\n Y/N: " << endl;
        recentAccident = setQualification(cin);
        cout << "Does the driver have a negative police record?\n Y/N: " << endl;
        policeRecord = setQualification(cin);
        cout << "checking for outstanding tickets: " << endl;
        ticketOutstanding = ticket->getTicketStatus("warrant outstanding", trn);
        cout << "Applicant has ticket due: " << (ticketOutstanding == 1 ? "True" : "False") << endl;
        //increment application id
        appID += numApplicationSaved;
        //Save application to file
        SaveApplication(appID);
        //increment the number of applications saved
        numApplicationSaved++;
    }


    //function to update Application details
    void UpdateApplication()
    {

        int userInput;
        cout << "Enter the Applicants Tax Registration Number: " << endl;
        cin >> userInput;

        int id = findTrn(userInput);

        if (id == -1)
        {

            cout << "User not Found" << endl;
        }
        else
        {
            cout << "User Found" << endl;
            retrieveApplication(id);
            updateMenuHandler();
        }
    }

    void showAllApplicants()
    {

        try
        {
            ifstream raFile(appFilename, ios::in | ios::out | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot retrieve record");
            }
            cout << "Applications Saved: " << numApplicationSaved << endl;
            for (int index = 0; index < numApplicationSaved; index++)
            {

                raFile.seekg((index) * sizeof(*this));
                raFile.read(reinterpret_cast<char *>(this), sizeof(*this));
                Display();
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

    void Display()
    {
        Driver::Display();
        cout << "Recent Accident: " << (recentAccident == 1 ? "True" : "False") << endl;
        cout << "Police Record: " << (policeRecord == 1 ? "True" : "False") << endl;
        cout << "------------------" << endl;
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
        cout << "\n\t\t +------------------------+ Application Menu +------------------------+" << endl;
        cout << "\n\t\t | " CYN "1." RST "  Create Application                                             |" << endl;
        cout << "\n\t\t | " CYN "2." RST "  Update Application                                             |" << endl;
        cout << "\n\t\t | " CYN "3." RST "  Delete Application                                             |" << endl;
        cout << "\n\t\t | " CYN "4." RST "  Set Application  Status                                        |" << endl;
        cout << "\n\t\t | " CYN "5." RST "  Find Applicant Info                                            |" << endl;
        cout << "\n\t\t | " CYN "6." RST "  Show all Applicants                                            |" << endl;
        cout << "\n\t\t | " CYN "0." RST "  Exit                                                           |" << endl;
        cout << "\t\t +--------------------------------------------------------------------+" << endl;
        cout << "\nPlease select with the " CYN "digits" RST " on the left:  " << endl;
        // prompts for user choice
        cin >> choice;
        system("cls");
        // clears the screen
        return choice;
    }

    void handler()
    {
        int option = this->ShowMenu(); // get user option

        while (option != 0)
        { // Start while loop for main menu

            switch (option)
            { // case structure is used to determine option selected
            case 1:
                this->CreateApplication();
                break;
            case 2:
                UpdateApplication();
                SaveApplication(appID);
                break;
            case 3:
                this->DeleteApplication();
                break;
            case 4:
                this->setApplicationStatus();
                break;
            case 5:
                this->findApplicantInfo();
                break;
            case 6:
                this->showAllApplicants();
                break;
            default: // if an invalid number is entered
                cout << "Invalid option chosen" << endl;
                break;
            } // end switch case

            system("pause");
            option = this->ShowMenu(); // get user option
        }
    }

    void setApplicationStatus()
    {

        int Userinput;
        cout << "Enter the Applicants Tax Registration Number: " << endl;
        cin >> Userinput;

        int key = findTrn(Userinput);

        if (key != -1)
        {

            retrieveApplication(key);
            int option = statusMenu(); // get user option

            while (option != 0)
            { // Start while loop for main menu

                switch (option)
                { // case structure is used to determine option selected
                case 1:
                    writeFixedLengthString(status, "Approved");
                    break;
                case 2:
                    writeFixedLengthString(status, "Pending");
                    break;
                case 3:
                    writeFixedLengthString(status, "Rejected");
                    break;
                default: // if an invalid number is entered
                    cout << "Invalid option chosen" << endl;
                    break;
                } // end switch case

                system("pause");
                option = statusMenu(); // get user option
            }
        }
    }

    int statusMenu()
    {
        int choice;
        // Get current date and time
        time_t timestamp;
        time(&timestamp);
        system("cls");                                 // clears the screen
        cout << "Date: " << ctime(&timestamp) << endl; // print current date and time
        /*prints a menu so the user can select their desired choice*/
        cout << "\n\t\t +------------------------+ Application Menu +------------------------+" << endl;
        cout << "\n\t\t | " CYN "1." RST "  Set Approved                                                   |" << endl;
        cout << "\n\t\t | " CYN "2." RST "  Set Pending                                                    |" << endl;
        cout << "\n\t\t | " CYN "3." RST "  Set Rejected                                                   |" << endl;
        cout << "\n\t\t | " CYN "0." RST "  Exit                                                           |" << endl;
        cout << "\t\t +--------------------------------------------------------------------+" << endl;
        cout << "\nPlease select with the " CYN "digits" RST " on the left:  " << endl;
        // prompts for user choice
        cin >> choice;
        system("cls");
        // clears the screen
        return choice;
    }

    void findApplicantInfo()
    {

        int Userinput;
        cout << "Enter the Applicants Tax Registration Number: " << endl;
        cin >> Userinput;

        int key = findTrn(Userinput);
        if (key != -1)
        {
            retrieveDriver(key);
            Display();
        }
    }

    int findTrn(int searchQuery)
    {
        int foundIndex = -1;

        try
        {
            ifstream file(appFilename, ios::in | ios::binary);
            if (file.fail())
            {
                throw runtime_error("No files to search for");
            }
            for (int i = 0; i < MaxAppRecord; i++)
            {
                file.seekg(i * sizeof(*this));
                file.read(reinterpret_cast<char *>(this), sizeof(*this));
                if (this->trn == searchQuery)
                {
                    foundIndex = appID;
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

    void SaveApplication(int appID)
    {

        try
        {
            fstream raFile(appFilename, ios::in | ios::out | ios::binary);
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

    void DeleteApplication()
    {
        int Userinput;
        cout << "Enter the Applicants Tax Registration Number: " << endl;
        cin >> Userinput;

        int key = findTrn(Userinput);

        Applicant record;
        bool was_removed = false;                     // was at least one record removed
        ifstream fin(appFilename, ios::binary);       // open file in binary mode for reading
        ofstream fout("tmp_record.dat", ios::binary); // create temporary file to write records that should not be deleted to it, and then replace files
        while (fin.read((char *)&record, sizeof(Applicant)))
        {
            if (record.appID != key)
            {                                                         // if the record does not match
                fout.write((const char *)&record, sizeof(Applicant)); // write the value to the temporary file
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
        fin.close();                                   // close the input file
        fout.close();                                  // close the output file
        remove(appFilename.c_str());                   // delete the old main file
        rename("tmp_record.dat", appFilename.c_str()); // rename the temporary file to the main one

        numApplicationSaved--;
    }

    void retrieveApplication(int idx)
    {
        try
        {
            fstream raFile(appFilename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot retrieve record");
            }

            raFile.seekg((idx - OFFSET) * sizeof(*this));
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

    void initialiseList()
    {
        try
        {
            ifstream raFile(appFilename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot read database");
            }
            else
            {
                Applicant a1;

                for (int idx = 0; idx < MaxAppRecord; idx++)
                {
                    raFile.seekg((idx) * sizeof(a1));
                    raFile.read(reinterpret_cast<char *>(&a1), sizeof(a1));

                    if (a1.trn != 0)
                    {
                        numApplicationSaved++;
                    }
                    a1.trn = 0;
                }
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
            ofstream raFile(appFilename, ios::out | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("database cannot be created ");
                for (int idx = 0; idx < MaxAppRecord; idx++)
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

#endif
