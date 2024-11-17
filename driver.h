// Driver Class

#include <vector>
#include "Ticket.h"
#include "Applicant.h"
using namespace std;

class Driver:public Applicant
{

private:
    vector<Ticket> tickets; // list of tickets that driver has
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
    {
        this->trn = trn;
        name = driverName;
        emailAddr = email;
    }

    void display()
    {
        cout << "Trn: " << trn << endl;
        cout << "Name:" << name << endl;
        cout << "Email Address:" << emailAddr << endl;
        cout << "----------------------------" << endl;
        currAddr.Display();
        cout << "----------------------------" << endl;
      
    }
};
