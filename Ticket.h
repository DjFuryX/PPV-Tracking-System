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

    // Setters
    void setTicketTrn(int newTrn)
    {
        trn = newTrn;
    }

    void setIssueDate()
    {
        issueDate.setDate();
    }

    void setDueDate()
    {

        dueDate.setDate();
    }

    void setLicensePlateNumber()
    {
        getInput(cin, licensePlateNumber);
    }

    void setTicketStatus(string newStatus)
    {
        writeFixedLengthString(status, newStatus);
    }

    void setIssueOfficerName(string officerName)
    {
        writeFixedLengthString(issueOfficer, officerName);
    }

    void setIssueOfficerStation(string officerStation)
    {
        writeFixedLengthString(issueOfficer, officerStation);
    }

    void setIssueParish(string issueParish)
    {
        writeFixedLengthString(issueOfficer, issueParish);
    }

    // Getters
    string getSation()
    {
        return issueStation;
    }

    string getissueParish()
    {

        return issueParish;
    }

    void createTicket(int badgenumber, string officerName, string officerStation, string officerParish, int driverTrn)
    {
        ticketNumber = ticketsSaved;
        cout << "Please Enter License Plate Number: " << endl;
        setLicensePlateNumber();
        addFine();
        cout << "Please set issue date" << endl;
        setIssueDate();
        cout << "Please set tickect due date" << endl;
        setDueDate();
        setTicketStatus("unpaid");
        setIssueOfficerName(officerName);
        setIssueOfficerStation(officerStation);
        setIssueParish(officerParish);
        trn = driverTrn;
        issueBageNumber = badgenumber;
        saveTicket(ticketNumber);
        ticketsSaved++;
    }

    void addFine()
    {
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

    int updateMenu()
    {
        int choice;
        // Get current date and time
        time_t timestamp;
        time(&timestamp);
        system("cls");                                 // clears the screen
        cout << "Date: " << ctime(&timestamp) << endl; // print current date and time
        /*prints a menu so the user can select their desired choice*/
        cout << "\n\t\t +------------------------+ Update Menu +---------------------+" << endl;
        cout << "  \t\t | " CYN "1." RST "  Change Offender TRN                                    |" << endl;
        cout << "\n\t\t | " CYN "2." RST "  Change Issue Date                                      |" << endl;
        cout << "\n\t\t | " CYN "3." RST "  Change Due Date                                        |" << endl;
        cout << "\n\t\t | " CYN "4." RST "  Change Issue Officer                                   |" << endl;
        cout << "\n\t\t | " CYN "5." RST "  Cahnge Issue Station                                   |" << endl;
        cout << "\n\t\t | " CYN "6." RST "  Change Issue Parish                                    |" << endl;
        cout << "\n\t\t | " CYN "0." RST "  Exit                                                   |" << endl;
        cout << "\t\t +------------------------------------------------------------+" << endl;
        cout << "\nPlease select with the " CYN "digits" RST " on the left:  " << endl;
        // prompts for user choice
        cin >> choice;
        system("cls");
        // clears the screen
        return choice;
    }

    void updateTicket(int drivertrn)
    {
        
        int ticketId;
        showAllTickets(drivertrn);

        cout << "Please Enter Id of Ticket to edit: " << endl;
        cin >> ticketId;
        retreiveTicket(ticketId);

        int option = updateMenu(); // get user option

        while (option != 0)
        { // Start while loop for main menu

            switch (option)
            { // case structure is used to determine option selected
            case 1:
                cout << "Please enter new Trn" << endl;
                cin >> trn;
                break;
            case 2:
                cout << "Please New  Issue Address" << endl;
                issueDate.setDate();
                break;
            case 3:
                cout << "Please New  Due Address" << endl;
                dueDate.setDate();
                break;
            case 4:
                cout << "Plese enter New issue Officer" << endl;
                getInput(cin, issueOfficer);
                break;
            case 5:
                cout << "Plese enter New issue Station" << endl;
                getInput(cin, issueStation);
                break;
            case 6:
                cout << "Plese enter New issue Parish" << endl;
                getInput(cin, issueParish);
                break;
            default: // if an invalid number is entered
                cout << "Invalid option chosen" << endl;
                break;
            } // end switch case
            option = updateMenu(); // get user option
        }
        saveTicket(ticketId);
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
            amount -= ticketAmount;
            ticketAmount -= ticketAmount;
            cout << "your change is : $" << amount << endl;
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

        saveTicket(number);
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
            fstream raFile(ticketFilename, ios::in | ios::out | ios::binary);
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
