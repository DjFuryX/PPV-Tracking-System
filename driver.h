// Driver Class
#include <iostream>
#include <time.h>
#include<vector>

#include "Address.h"
#include "Ticket.h"
using namespace std;

class Driver
{
protected:
    int trn;
    string name;
    string emailAddr;
    Address currAddr;
    time_t dob;
    vector <Ticket> tickets;//list of tickets that driver has
    

    // int unpaidTickets;
    // float totalfineAmount;
public:
    Driver()
    {
        trn = 0;
        name = "not Set";
        emailAddr = "NotSet@email.com";
    }

    Driver(int trn, string driverName, string email, time_t dateOfBirth, string street, string city, string parish)
        : currAddr(street, city, parish)
    {
        this->trn = trn;
        name = driverName;
        emailAddr = email;
        dob = dateOfBirth;
    }

    void display()
    {
        cout << "Trn: " << trn << endl;
        cout << "Name:" << name << endl;
        cout << "Email Address:" << emailAddr << endl;
        cout << "----------------------------" << endl;
        currAddr.display();
        cout << "----------------------------" << endl;
        cout << ctime(&dob) << endl;
    }
};

