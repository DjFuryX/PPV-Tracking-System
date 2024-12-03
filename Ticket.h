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
    char status[maxStringsize];
    float ticketAmount;
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
        writeFixedLengthString(status, "Notset");
    }

    // Getters
    void createTicket(char officer[], char stationParish[], int driverTrn)
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
        trn = driverTrn;
        writeFixedLengthString(issuingOfficer, officer);
        courtLocation.setParish(stationParish);
        saveTicket(ticketNumber);
        ticketsSaved++;
    }

    // Generates Ticket Report of Driver
    void viewTicketReport()
    {
        cout << "Offender Trn: " << trn << endl;
        cout << "Issue Date: " << endl;
        issueDate.Display();
        cout << "License Plate Number: " << licensePlateNumber << endl;
        cout << "Ticket Amount: $" << ticketAmount << endl;
        cout << "Ticket Status: $" << status << endl;
        cout << "Due Date: " << dueDate << endl;
        // cout << "Court Date: " << courtDate << endl;
        cout << "Issuing Officer: " << issuingOfficer << endl;
        // cout << "Court Location: " << courtLocation.GetParish() << endl;
        cout << RED << "---------------------" << endl;
        cout << "Fines: " << endl;
        Fine *fine = new Fine();
        fine->showAll(ticketNumber);
        cout << "---------------------" << RST << endl;
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
                setTicketStatus();

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

    void showTicketsByParish(string ticketParish)
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

                if (stricmp(courtLocation.GetParish().c_str(), ticketParish.c_str()) == 0)
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

                setTicketStatus();

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
