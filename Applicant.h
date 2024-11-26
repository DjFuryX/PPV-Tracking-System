// Applicant Class
#include <string>
#include <iostream>
#include <fstream>
#include "Address.h"
#include "Date.h"
using namespace std;

#ifndef Applicant_H
#define Applicant_H

string filename = "ApplicationList.dat";
int OFFSET = 100;

const int MaxAppRecord = 500;
int numApplicationSaved = 0;

class Applicant
{

protected:
    int trn;
    int appID;
    int contactnumber;
    string denyReason;
    string name;
    string emailAddr;
    Address currAddr;
    Date dob;

public:
    Applicant()
    {
        appID = 100;
        trn = 0;
        name = "NotSet";
        emailAddr = "NotSet";
        contactnumber = 12232323;
        denyReason = "NotSet";
    }

    int getappID()
    {
        return appID;
    }

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

    void CreateApplication()
    {
        cout << "Please Enter Appicants TRN" << endl;
        cin >> trn;

        cout << "Please Enter Applicant's Full Name" << endl;
        cin >> name;

        cout << "Please Enter Applicant's Date of Birth" << endl;
        dob.SetDob();

        cout << "Please Enter Applicant's Address" << endl;
        currAddr.SetAdrress();

        cout << "Please Enter Applicant's Email Address" << endl;
        cin >> emailAddr;

        cout << "Please Enter Applicant's Contact Number" << endl;
        cin >> contactnumber;

        SaveApplication(appID + numApplicationSaved);
    }

    void Display()
    {
        cout << "Applicant's Id: " << appID << endl;
        cout << "Applicant's TRN: " << trn << endl;
        cout << "Applicant's Name: " << name << endl;
        cout << "Applicant's Email Address: " << emailAddr << endl;
        cout << "Applicant's Contact Number: " << contactnumber << endl;
        cout << "Applicant's Date of Birth: " << endl;
        dob.Display();
        cout << "Applicant's Address" << endl;
        currAddr.Display();
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
        cout << "\n\t\t +--------------------------------+ Application Menu +--------------------------------+" << endl;
        cout << "\t\t | " CYN "1." RST "    Create Application                                                                    |" << endl;
        cout << "\n\t\t | " CYN "2." RST "   Update Application                                                         |" << endl;
        cout << "\n\t\t | " CYN "3." RST "    Delete Application                                                        |" << endl;
        cout << "\n\t\t | " CYN "4." RST "    Reject Application                                                        |" << endl;
        cout << "\n\t\t | " CYN "4." RST "    Check Driver Status                                                       |" << endl;
        cout << "\n\t\t | " CYN "0." RST "    Exit                                                                      |" << endl;
        cout << "\t\t +---------------------------------------------------------------------------------+" << endl;
        cout << "\nPlease select with the " CYN "digits" RST " on the left:  " << endl; // prompts for user choice
        cin >> choice;
        system("cls");
        // clears the screen
        return choice;
    }

    void applicantHandler()
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

                break;

            default: // if an invalid number is entered
                cout << "Invalid option chosen" << endl;
                break;
            } // end switch case

            system("pause");
            option = this->ShowMenu(); // get user option
        }
    }

    int Findtrn()
    {
        int searchQuery;

        cout << "Please enter TRN: ";
        cin >> searchQuery;

        try
        {
            ofstream file(filename, ios::out | ios::binary);
            if (file.fail())
            {
                throw runtime_error("No files to search for");
            }
            for (int i = 0; i < MaxAppRecord; i++)
            {
                file.seekp(i * sizeof(*this));

                if (this->trn == searchQuery)
                {
                    retrieveApplication(i);
                }
            }
            file.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    void SaveApplication(int id)
    {
        try
        {
            fstream file(filename, ios::out | ios::binary);
            if (file.fail())
            {
                throw runtime_error("Exception: storing record");
            }
            file.seekp((id - OFFSET) * sizeof(*this));
            file.write(reinterpret_cast<char *>(this), sizeof(*this));
            cout << id - OFFSET << "-:TRN: " << this->trn << endl;
            file.close();
        }
        catch (runtime_error &error)
        {
            cerr << error.what() << endl;
        }
    }

    void retrieveApplication(int id)
    {

        try
        {
            ifstream file(filename, ios::in | ios::binary);
            if (file.fail())
            {
                throw runtime_error("Exception: retrieving record");
            }
            file.seekg((id - OFFSET) * sizeof(*this));
            file.read(reinterpret_cast<char *>(this), sizeof(*this));
            file.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    void initialiseApplicantList()
    {
        try
        {
            ifstream file(filename, ios::in | ios::binary);

            if (file.fail())
            {
                throw runtime_error("Database was Empty ");
            }
            else
            {
                for (int i = 0; i < MaxAppRecord; i++)
                {
                    // Temporary buffer to read applicant data
                    Applicant tempRecord;              // Assuming your class has a struct or class for applicants
                    file.seekg(i * sizeof(tempRecord)); // Adjust type here
                    file.read(reinterpret_cast<char *>(&tempRecord), sizeof(tempRecord));

                    if (tempRecord.trn != 0) // Check the record's TRN
                    {
                        numApplicationSaved++;
                        
                        // Store the valid record in your list, e.g., applicantList[i] = tempRecord;
                    }
                }
                file.close();
            }
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;

            // If the database is empty, initialize it
            ofstream file(filename, ios::out | ios::binary);

            for (int i = 0; i < MaxAppRecord; i++)
            {
                // Write default ApplicantRecord to initialize the database
                Applicant tempRecord; // Use a default constructor to initialize
                file.seekp(i * sizeof(tempRecord));
                file.write(reinterpret_cast<const char *>(&tempRecord), sizeof(tempRecord));
            }
            file.close();
        }
    }
};

#endif
