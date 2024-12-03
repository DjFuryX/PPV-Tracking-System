// Ticket Class
#include "Date.h"
#include "Address.h"
#include "Fine.h"
#include <iostream>
#include <fstream>

using namespace std;

#ifndef Ticket_H
#define Ticket_H

const string ticketFilename = "Ticketlist.dat";
int ticketsSaved = 0;
const int Maxticket = 500;

class Ticket
{
private:
    int ticketNumber;
    int trn;
    char issuingOfficer[maxStringsize];
    char licensePlateNumber[maxStringsize];
    float ticketAmount;
    Fine ticketFine;
    Date dueDate;
    Date courtDate;
    Date issueDate;
    Address courtLocation;

public:
    Ticket() // default constructor
    {
        ticketNumber = -1;
        writeFixedLengthString(issuingOfficer, "OfficerNotSet");
        writeFixedLengthString(licensePlateNumber, "00-0000");
        ticketAmount = 0.0;
        trn = 0;
    }

    // Primary Constructor

    /* Ticket(int ticNum, string issueDate, string offenceDes, string offenceCode, string plateNumber,
           float tAmount, string due, string court, string issueOfficer, string cLocation)
    {
        ticketNumber = ticNum;
        ticketIssueDate = issueDate;
        ticketOffenceCode = offenceCode;
        ticketOffenceDescription = offenceDes;
        licensePlateNumber = plateNumber;
        ticketAmount = tAmount;
        dueDate = due;
        courtDate = court;
        issuingOfficer = issueOfficer;
        courtLocation = cLocation;
    } */

    // Getters
    void createTicket(char officer[], char stationParish[], int driverTrn)
    {
        cout << "Please Enter License Plate Number: " << endl;
        getInput(cin, licensePlateNumber);
        char option[1];
        do
        {
            ticketFine.addFine(ticketNumber);
            ticketAmount+=ticketFine.getAmount();
            cout << "Would you like to add another fine (y/n)" << endl;
            getInput(cin, option);

            option[0] = tolower(option[0]);

        } while (strcmp(option, "y") == 0);

        cout << "Please set issue date" << endl;
        issueDate.setDate();
        cout << "Please set tickect due date" << endl;
        dueDate.setDate();

        trn = driverTrn;
        writeFixedLengthString(issuingOfficer, officer);
        courtLocation.setParish(stationParish);
        
        ticketNumber=ticketsSaved;
        saveTicket(ticketNumber);
        ticketsSaved++;

    }

    // Generates Ticket Report of Driver
    void viewTicketReport()
    {
        cout << "Ticket Number: " << ticketNumber << endl;
        cout << "Issue Date: " << endl;
        issueDate.Display();
        cout << "License Plate Number: " << licensePlateNumber << endl;
        cout << "Ticket Amount: $" << ticketAmount << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Court Date: " << courtDate << endl;
        cout << "Issuing Officer: " << issuingOfficer << endl;
        cout << "Court Location: " << courtLocation.GetParish() << endl;
        cout<<"Fines: "<<endl;
        ticketFine.showAll(ticketNumber);
    }

    void showAllTickets()
    {

        try
        {
            ifstream raFile(ticketFilename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot retrieve record");
            }
            cout << "Tickets Saved: " << ticketsSaved << endl;
            for (int index = 0; index < ticketsSaved; index++)
            {

                raFile.seekg((index) * sizeof(*this));
                raFile.read(reinterpret_cast<char *>(this), sizeof(*this));
                viewTicketReport();
            }
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    void saveTicket(int ticketId)
    {

        try
        {
            // ofstream raFile(driverFilename, ios::binary | ios::app);
            ofstream raFile(ticketFilename, ios::binary | ios::out);
            if (raFile.fail())
            {
                throw runtime_error("cannot create database");
            }
            raFile.seekp((ticketId) * sizeof(*this));
            raFile.write(reinterpret_cast<const char *>(this), sizeof(*this));
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    void retreiveTicket(int ticketId)
    {
        try
        {
            fstream raFile(ticketFilename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot retrieve record");
            }

            raFile.seekg((ticketId) * sizeof(*this));
            raFile.read(reinterpret_cast<char *>(this), sizeof(*this));
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    virtual void initialiseList()
    {
        try
        {
            ifstream raFile(ticketFilename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot read database");
            }
            else
            {
                Ticket ticket;

                for (int idx = 0; idx < Maxticket; idx++)
                {
                    raFile.seekg((idx) * sizeof(ticket));
                    raFile.read(reinterpret_cast<char *>(&ticket), sizeof(ticket));

                    if (ticket.ticketNumber != -1)
                    {
                        ticketsSaved++;
                    }
                    ticket.ticketNumber = -1;
                }

                cout << "Number of Tickets saved: " << ticketsSaved << endl;
                raFile.close();
            }
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
            createBlankRecords();
        }
    }

    virtual void createBlankRecords()
    {
        try
        {
            ofstream raFile(ticketFilename, ios::out | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("database cannot be created ");
                for (int idx = 0; idx < Maxticket; idx++)
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
