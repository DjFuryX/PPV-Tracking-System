// Applicant Class
#include <string>
#include <iostream>
#include <fstream>
#include "Address.h"
#include "Date.h"

using namespace std;

class Applicant
{
protected:
    int trn;
    int appID = 100;
    int contactnumber;
    string name;
    string emailAddr;
    Address currAddr;
    Date dob;
    char denyReason[100];
    static int totalApp;
    const int MaxAppRecord = 500;
    string filename = "ApplicationList";

public:
    Applicant()
    {
        appID = 0;
        trn = 0;
        name = "NotSet";
        emailAddr = "NotSet";
        contactnumber = 0;
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
        cin.ignore();
        getline(cin, name, '\n');

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

        cout << "Appicants TRN " << trn << endl;
        cout << "Applicant's Full Name " << name << endl;
        cout << "Applicant's Email Address " << emailAddr << endl;
        cout << "Applicant's Contact Number " << contactnumber << endl;
        cout << "Applicant's Date of Birth " << endl;
        dob.Display();
        cout << "Applicant's Address" << endl;
        currAddr.Display();
    }

    void SaveApplication()
    {
        string filename;
        int OFFSET = 100;

        try
        {
            fstream file(filename.append(".dat"), ios::out | ios::binary);
            if (file.fail())
            {
                throw runtime_error("Exception: storing record");
            }
            file.seekp((appID - OFFSET) * sizeof(*this));
            file.write(reinterpret_cast<const char *>(this), sizeof(*this));
            cout << reinterpret_cast<const char *>(this), sizeof(*this);
            file.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    void SaveApplicationSeq()
    {
        try
        {
            ofstream dataFile(filename.append(".txt"), ios::app);

            if (dataFile.fail())
            {
                throw runtime_error("cannot access file");
            }

            dataFile << "Appicants TRN: " << trn << endl;
            dataFile << "Applicant's Full Name: " << name << endl;
            dataFile << "Applicant's Email Address: " << emailAddr << endl;
            dataFile << "Applicant's Contact Number: " << contactnumber << endl;
            dataFile << "Applicant's Date of Birth: " << endl;
            dataFile << dob;
            dataFile << "Applicant's Address: " << endl;
            dataFile << currAddr;
            dataFile.close();
        }
        catch (runtime_error &err)
        {
            cerr << err.what() << endl;
        }
    }
};

// initialize static attribute
int Applicant::totalApp = 0;

// Overrides How the objects of this class are stored as string
ostream &operator<<(ostream &out, Applicant &c)
{
    out << c.getappID() << c.GetTrn() << c.GetContactNumner() << c.GetContactNumner();
    out << c.GetAddress().GetStreet() << c.GetAddress().GetCity() << c.GetAddress().GetParish();
    out << c.GetDob().GetDay() << c.GetDob().GetMonth() << c.GetDob().GetYear();
    return out;
}