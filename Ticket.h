//Ticket Class


#include<iostream>
#include <string>
using namespace std;

#ifndef MYHEADEFILE_H
#define MYHEADEFILE_H

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

       // Getters

       int getTicketNumber(){
            return ticketNumber;
            }
       string getTicketIssueDate(){ 
            return ticketIssueDate; 
            }
       string getTicketOffenceCode(){
            return ticketOffenceCode; 
            }
        string getTicketOffenceDescription(){ 
            return ticketOffenceDescription; 
            }
        string getLicensePlateNumber(){ 
            return licensePlateNumber; 
            }
        float getTicketAmount(){ 
            return ticketAmount; 
            }
        string getDueDate(){ 
            return dueDate; 
            }
        string getCourtDate(){ 
            return courtDate; 
            }
        string getIssuingOfficer(){ 
            return issuingOfficer; 
            }
        string getCourtLocation(){ 
            return courtLocation; 
            }

        //Setter Methods

        void setTicketNumber(int ticNum) { 
            ticketNumber = ticNum; 
            }
        void setTicketIssueDate(string issueDate) { 
            ticketIssueDate = issueDate; 
            }
        void setTicketOffenceCode(string offenceCode) { 
            ticketOffenceCode = offenceCode; 
            }
        void setTicketOffenceDescription(string offenceDes) { 
            ticketOffenceDescription = offenceDes; 
            }
        void setLicensePlateNumber(string plateNumber) { 
            licensePlateNumber = plateNumber; 
            }
        void setTicketAmount(float tAmount) { 
            ticketAmount = tAmount; 
            }
        void setDueDate(string due) { 
            dueDate = due; 
            }
        void setCourtDate(string court) { 
            courtDate = court; 
            }
        void setIssuingOfficer(string issueOfficer) { 
            issuingOfficer = issueOfficer; 
            }
        void setCourtLocation(string cLocation) { 
            courtLocation = cLocation; 
            }


        // Generates Ticket Report of Driver
        void viewTicketReport(){
            cout << "Ticket Bumber: "<< ticketNumber << endl;
            cout << "Issue Date: " << ticketIssueDate << endl;
            cout << "Offence Code: " <<ticketOffenceCode << endl;
            cout << "Offence dEscription: " <<ticketOffenceDescription << endl;
            cout << "License Plate Number: " << licensePlateNumber << endl;
            cout << "Ticket Amount: $" << ticketAmount << endl;
            cout << "Due Date: " << dueDate << endl;
            cout << "Court Date: " << courtDate << endl;
            cout << "Issuing Officer: " << issuingOfficer << endl;
            cout << "Court Location: " << courtLocation << endl;
        }

};

#endif