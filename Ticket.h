//Ticket Class

#include<iostream>
using namespace std;

class Ticket
{
private:
    int ticketNumber;
    string ticketIssueDate;
    string ticketOffenceCode;
    string ticketOffenceDescription;
    string licensePlateNumber;
    float ticketAmount;
    string dueDate;
    string courtDate;
    string issuingOfficer;
    string courtLocation;

    public:
        Ticket()// default constructor
       {
        ticketNumber=0;
        ticketIssueDate="notSet";
        ticketOffenceCode="notSet";
        ticketOffenceDescription="notSet";
        licensePlateNumber="AA-0000";
        ticketAmount=0.0;
        dueDate="notSet";
        courtDate="notSet";
        issuingOfficer="notSet";
        courtLocation="notSet";
       }

       Ticket(int ticNum, string issueDate, string offenceDes, string offenceCode, string plateNumber, 
       float tAmount, string due, string court, string issueOfficer, string cLocation)
       {
        ticketNumber = ticNum;
        ticketIssueDate = issueDate;
        ticketOffenceCode = offenceCode;
        ticketOffenceDescription = offenceDes;
        licensePlateNumber = plateNumber;
        ticketAmount = tAmount;
        dueDate = due;
        courtDate= court;
        issuingOfficer= issueOfficer;
        courtLocation= cLocation;
       }


};