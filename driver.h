// Driver Class
#include <stdexcept> 
#include <iostream>
#include <string>
#include "Date.h"
#include "Address.h"
#include "User.h"
#include "Ticket.h"
using namespace std;

#ifndef Driver_h
#define Driver_h

class Driver:public User
{
    protected:
    int trn;
    int appID;
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

    void createDriver()
    {
        setTrn();
        setName();
        setDob();
        setContactNumber();
        setAddress();
        setEmailAddress();
    }



    void Login() 
    {
        try
        {
            // Display Driver's login prompt
            cout << "\n\t\t +----------------------------+ Driver Login +----------------------------+\n" << endl;
            cout << "\t\tPlease enter TRN:\t";
            int enteredTRN;
            cin >> enteredTRN;  // Input the TRN

            cout << "\t\tPlease enter Password:\t";
            int enteredPassword;  // Password as an integer
            cin >> enteredPassword;  // Input the password

            if (enteredTRN <= 0 || enteredPassword <= 0)
            {
                throw runtime_error("Invalid TRN or password. Please try again.");
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

};


#endif // Driver_h