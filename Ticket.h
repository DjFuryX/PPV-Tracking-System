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
    char licensePlateNumber[maxStringsize];
    char status[maxStringsize];
    float ticketAmount;
    Date dueDate;
    Date courtDate;
    Date issueDate;
    int issueBageNumber;
    char issueOfficer[maxStringsize];
    char issueParish[maxStringsize];
    char issueStation[maxStringsize];

public:
    Ticket() // default constructor
    {
        ticketNumber = -1;
        writeFixedLengthString(licensePlateNumber, "00-0000");
        ticketAmount = 0.0;
        trn = 0;
        writeFixedLengthString(status, "Notset");
    }

    // Getters
    string getSation()
    {
        return issueStation;
    }

    void createTicket(int badgenumber, string officerName, string officerStation, string officerParish, int driverTrn)
    {
        ticketNumber = ticketsSaved;
        cout << "Please Enter License Plate Number: " << endl;
        getInput(cin, licensePlateNumber);
        char option[1];

        do
        {
            Fine newfine;
            newfine.addFine(ticketNumber);
            ticketAmount += newfine.getAmount();

            cout << "Would you like to add another fine (y/n)" << endl;
            getInput(cin, option);
            option[0] = tolower(option[0]);

        } while (strcmp(option, "y") == 0);

        cout << "Please set issue date" << endl;
        issueDate.setDate();
        cout << "Please set tickect due date" << endl;
        dueDate.setDate();
        writeFixedLengthString(status, "unpaid");
        writeFixedLengthString(issueOfficer, officerName);
        writeFixedLengthString(issueStation, officerStation);
        writeFixedLengthString(issueParish, officerParish);
        trn = driverTrn;
        issueBageNumber = badgenumber;

        saveTicket(ticketNumber);
        ticketsSaved++;
    }

    // Generates Ticket Report of Driver
    void viewTicketReport()
    {
        cout << "Ticket ID: " << ticketNumber << endl;
        cout << "Offender Trn: " << trn << endl;
        cout << "Issue Date: " << issueDate << endl;
        cout << "License Plate Number: " << licensePlateNumber << endl;
        cout << "Ticket Amount: $" << ticketAmount << endl;
        cout << "Ticket Status: " << status << endl;
        cout << "Due Date: " << dueDate << endl;
        cout << "Issuing Officer: " << issueOfficer << endl;
        cout << "Fines: " << endl;
        Fine *fine = new Fine();
        fine->showAll(ticketNumber);
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
                this->viewTicketReport();
            }
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    void showAllTickets(int driverTrn)
    {

        try
        {
            ifstream raFile(ticketFilename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot retrieve record");
            }
            for (int index = 0; index < ticketsSaved; index++)
            {

                raFile.seekg((index) * sizeof(*this));
                raFile.read(reinterpret_cast<char *>(this), sizeof(*this));
                if (this->trn == driverTrn)
                {
                    this->viewTicketReport();
                }
            }
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    void showAllTickets(int driverTrn, string status)
    {

        try
        {
            ifstream raFile(ticketFilename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot retrieve record");
            }
            for (int index = 0; index < ticketsSaved; index++)
            {

                raFile.seekg((index) * sizeof(*this));
                raFile.read(reinterpret_cast<char *>(this), sizeof(*this));
                if (this->trn == driverTrn && strcmp(this->status, status.c_str()) == 0)
                {
                    this->viewTicketReport();
                }
            }
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    void showAllTickets(string ticketStatus)
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
                if (strcmp(this->status, ticketStatus.c_str()) == 0)
                {

                    viewTicketReport();
                }
            }
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    void setTicketStatus()
    {
        if (issueDate.daysToDueDate(dueDate) >= 21)
        {
            writeFixedLengthString(this->status, "warrant outstanding");
        }
    }

    void payTicket()
    {
        int number;
        float amount;
        cout << "Please enter ticket id Number: " << endl;
        cin >> number;
        retreiveTicket(number);
        cout << "Please enter amount to pay: " << endl;
        cin >> amount;

        if (amount > ticketAmount)
        {
            amount-=ticketAmount;
            ticketAmount -= ticketAmount;
            cout << "your change is : $" << amount<< endl;
        }
        else
        {
            ticketAmount -= amount;
        }

        if (ticketAmount == 0)
        {
            writeFixedLengthString(status, "paid");
            cout << "ticket is now paid" << endl;
        }
        else
        {
            cout << "ticket is not fully paid Balance remaining: $" << ticketAmount << endl;
        }

        overWriteTicket(number);
    }

    bool getTicketStatus(string ticketStatus)
    {
        bool hasStatus = false;
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

                if (strcmp(this->status, ticketStatus.c_str()) == 0)
                {
                    hasStatus = true;
                }
            }
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
        return hasStatus;
    }

    bool getTicketStatus(string ticketStatus, int Offendertrn)
    {
        bool hasStatus = false;
        try
        {
            ifstream raFile(ticketFilename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot retrieve record");
            }
            for (int index = 0; index < ticketsSaved; index++)
            {

                raFile.seekg((index) * sizeof(*this));
                raFile.read(reinterpret_cast<char *>(this), sizeof(*this));

                if (strcmp(this->status, ticketStatus.c_str()) == 0 && Offendertrn == trn)
                {
                    hasStatus = true;
                }
            }
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
        return hasStatus;
    }

    void saveTicket(int ticketId)
    {

        try
        {
            ofstream raFile(ticketFilename, ios::binary | ios::app);
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

    void overWriteTicket(int ticketId)
    {

        try
        {
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
                        // check if ticket is overdue
                        setTicketStatus();
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
