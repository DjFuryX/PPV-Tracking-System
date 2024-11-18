// Applicant Class
#include <string>
#include <iostream>
#include <fstream>
#include "Address.h"
#include "Date.h"

using namespace std;

class Applicant
{

private:
    string denyReason;
    const int MaxAppRecord = 500;
    const int MaxStringSize = 50;
    static int totalApp;

protected:
    int trn;
    int appID = 100;
    int contactnumber;
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

    void SetTRn(istream &stream)
    {
        stream >> trn;
    }

    void SetName(istream &stream)
    {
        try
        {
            stream.ignore();
            getline(stream, name, '\n');
            if (name.length() > MaxStringSize)
            {
                throw runtime_error("Name should not exceed " + to_string(MaxStringSize) + " characters");
            }
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
            SetName(cin);
        }
    }

    void CreateApplication()
    {
        cout << "Please Enter Appicants TRN" << endl;
        SetTRn(cin);

        cout << "Please Enter Applicant's Full Name" << endl;
        SetName(cin);

        cout << "Please Enter Applicant's Date of Birth" << endl;
        dob.SetDob();

        cout << "Please Enter Applicant's Address" << endl;
        currAddr.SetAdrress();

        cout << "Please Enter Applicant's Email Address" << endl;
        cin >> emailAddr;

        cout << "Please Enter Applicant's Contact Number" << endl;
        cin >> contactnumber;
        totalApp += 1;
    }

    void Display()
    {
        cout << "Applicant's Id: " << appID << endl;
        cout << "Applicant's TRN: " << trn << endl;
        cout << "Applicant's Full Name: " << name << endl;
        cout << "Applicant's Email Address: " << emailAddr << endl;
        cout << "Applicant's Contact Number: " << contactnumber << endl;
        cout << "Applicant's Date of Birth: " << endl;
        dob.Display();
        cout << "Applicant's Address" << endl;
        currAddr.Display();
        cout << "------------------" << endl;

    }

    void SaveApplication()
    {
        int OFFSET = 99;
        string filename = "ApplicationList.dat";
        try
        {
            fstream file(filename, ios::out | ios::binary);
            if (file.fail())
            {
                throw runtime_error("Exception: storing record");
            }
            file.seekp((appID - OFFSET) * sizeof(*this));
            file.write(reinterpret_cast<char *>(this), sizeof(*this));
            file.close();
        }
        catch (runtime_error &error)
        {
            cerr << error.what() << endl;
        }
    }

    void retrieveApplication(int id)
    {
        string filename = "ApplicationList.dat";

        int OFFSET = 99;
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

    void CreateBlankRecords()
    {
        string filename = "ApplicationList.dat";
        try
        {
            ofstream file(filename, ios::out | ios::binary);
            if (file.fail())
            {
                throw runtime_error("Exception: Initializing database!");
            }
            for (int i = 0; i < MaxAppRecord; i++)
            {
                file.seekp(i * sizeof(*this));
                file.write(reinterpret_cast<const char *>(this), sizeof(*this));
            }
            file.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }


};

// initialize static attribute
int Applicant::totalApp = 0;
