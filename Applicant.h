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

int OFFSET = 100;
const int MaxAppRecord = 500;
const string filename = "ApplicationList.dat";
int numApplicationSaved = 0;
const int maxStringsize = 50;

class Applicant
{

protected:
    int trn;
    int appID;
    int contactnumber;
    char name[maxStringsize];
    char denyReason[maxStringsize];
    char emailAddr[maxStringsize];
    char status[maxStringsize];
    Address currAddr;
    Date dob;
    bool recentAccident;
    bool policeRecord;

public:
    Applicant()
    {
        appID = 100;
        trn = 0;
        contactnumber = 0;
        writeFixedLengthString(name, "NotSet");
        writeFixedLengthString(emailAddr, "Notset");
        writeFixedLengthString(denyReason, "NotSet");
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

    bool setQualification(istream &stream)
    {
        string userInput;
        try
        {
            stream.ignore();
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

    void CreateApplication()
    {
        setTrn();
        setName();
        setDob();
        setContactNumber();
        setAddress();
        setEmailAddress();
        cout << "Did the driver cause any accident(s) within the last two years?\n Y/N: " << endl;
        recentAccident = setQualification(cin);
        cout << "Does the driver have a negative police record?\n Y/N: " << endl;
        policeRecord = setQualification(cin);

        appID += numApplicationSaved;
        SaveApplication(appID);
        numApplicationSaved++;
    }

    void UpdateApplication()
    {

        int Userinput;

        cout << "Enter the Applicants Tax Registration Number: " << endl;
        cin >> Userinput;

        if (findTrn(Userinput) == -1)
        {

            cout << "User not Found" << endl;
        }
        else
        {
            cout << "User Found" << endl;
        }
        updateMenuHandler();
    }

    void DeleteApplication()
    {
        int Userinput;
        cout << "Enter the Applicants Tax Registration Number: " << endl;
        cin >> Userinput;

        int key = findTrn(Userinput);

        Applicant record;                             
        bool was_removed = false;             // was at least one record removed
        ifstream fin(filename, ios::binary);       // open file in binary mode for reading
        ofstream fout("tmp_record.dat", ios::binary); // create temporary file to write records that should not be deleted to it, and then replace files
        while (fin.read((char *)&record, sizeof(Applicant)))
        {
            if (record.appID != key)
            {                                                 // if the record does not match
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
        fin.close();                    // close the input file
        fout.close();                   // close the output file
        remove(filename.c_str());                   // delete the old main file
        rename("tmp_record.dat", filename.c_str()); // rename the temporary file to the main one
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
        cout << "\n\t\t +--------------------------------+ Application Menu +--------------------------------+" << endl;
        cout << "\t\t | " CYN "1." RST "    Create Application                                                            |" << endl;
        cout << "\n\t\t | " CYN "2." RST "   Update Application                                                         |" << endl;
        cout << "\n\t\t | " CYN "3." RST "    Delete Application                                                        |" << endl;
        cout << "\n\t\t | " CYN "4." RST "    Reject Application                                                        |" << endl;
        cout << "\n\t\t | " CYN "4." RST "    Check Application Status                                                  |" << endl;
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
                currApplicant->UpdateApplication();
                break;
            case 3:
                currApplicant->DeleteApplication();
                break;
            default: // if an invalid number is entered
                cout << "Invalid option chosen" << endl;
                break;
            } // end switch case

            system("pause");
            option = this->ShowMenu(); // get user option
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
        cout << "\n\t\t +--------------------------------+ Application Menu +--------------------------------+" << endl;
        cout << "\t\t | " CYN "1." RST "    Change Name                                                           |" << endl;
        cout << "\n\t\t | " CYN "2." RST "   Change TRN                                                       |" << endl;
        cout << "\n\t\t | " CYN "3." RST "   Change Address                                                        |" << endl;
        cout << "\n\t\t | " CYN "4." RST "    Change Email Address                                                        |" << endl;
        cout << "\n\t\t | " CYN "4." RST "    Change Phone Number                                                 |" << endl;
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
            default: // if an invalid number is entered
                cout << "Invalid option chosen" << endl;
                break;
            } // end switch case
            SaveApplication(appID);
            system("pause");
            option = this->updateMenu(); // get user option
        }
    }

    int findTrn(int searchQuery)
    {
        int foundIndex = -1;

        try
        {
            ifstream file(filename, ios::in | ios::binary);
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
                    // retrieveApplication(i);
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
            // ofstream raFile(filename, ios::binary | ios::app);
            ofstream raFile(filename, ios::binary | ios::in);
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
