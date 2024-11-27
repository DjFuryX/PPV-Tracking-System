// Applicant Class
#include <string>
#include <iostream>
#include <fstream>
#include "Auxillary.h"
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
    char name[50];
    char denyReason[50];
    char emailAddr[50];
    Address currAddr;
    Date dob;

public:
    Applicant()
    {
        appID = 100;
        trn = 0;
        contactnumber = 0;
        writeFixedLengthString(name, 50, "NotSet");
        writeFixedLengthString(emailAddr, 50, "Notset");
        writeFixedLengthString(denyReason, 50, "NotSet");
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

    void setTrn()
    {
        cout << "Please Enter Appicants TRN" << endl;
        cin >> trn;
    }

    void setName()
    {
        cout << "Please Enter Applicant's Full Name" << endl;
        getInput(cin, name);
    }

    void setDob()
    {
        cout << "Please Enter Applicant's Date of Birth" << endl;
        dob.SetDob();
    }
    void setAddress()
    {
        cout << "Please Enter Applicant's Address" << endl;
        currAddr.SetAdrress();
    }

    void setEmailAddress()
    {
        cout << "Please Enter Applicant's Email Address" << endl;
        getInput(cin, emailAddr);
    }

    void setContactNumber()
    {
        cout << "Please Enter Applicant's Contact Number" << endl;
        cin >> contactnumber;
    }

    void CreateApplication()
    {
        setTrn();
        setName();
        setAddress();
        setDob();
        setEmailAddress();
        setContactNumber();

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
        cout << "\t\t | " CYN "1." RST "    Create Application                                                          |" << endl;
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

        Applicant *currApplicant = new Applicant();

        while (option != 0)
        { // Start while loop for main menu

            switch (option)
            { // case structure is used to determine option selected
            case 1:
                currApplicant->CreateApplication();
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

    int Findtrn(int searchQuery)
    {

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

    void SaveApplication(int appID)
    {

        try
        {
            ofstream raFile(filename, ios::out | ios::binary);
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

    void retrieveApplication(int idx)
    {
        try
        {
            fstream raFile(filename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot create database");
            }

            raFile.seekg((idx - OFFSET) * sizeof(*this));
            raFile.read(reinterpret_cast<char *>(this), sizeof(*this));
            raFile.close();
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
            ifstream raFile(filename, ios::in | ios::binary);
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
                    a1.trn=0;
                }
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
            ofstream raFile(filename, ios::out | ios::binary);
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
