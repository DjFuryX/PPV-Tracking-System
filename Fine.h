// Fine Class
#include <iostream>
#include "Auxillary.h"
#include <fstream>
using namespace std;

#ifndef Fine_h
#define Fine_h

const string filename = "Fineslist.dat";
int finesSaved = 0;
const int Maxfines = 500;

class Fine
{
private:
    char offenceCode[maxStringsize];
    char offenceDescription[100];
    float fineAmount;
    int fineId;
    int ticketId;

public:
    // Default Constructor
    Fine()
    {
        writeFixedLengthString(offenceCode, "Notset");
        writeFixedLengthString(offenceDescription, "notSet");
        fineAmount = 0.0;
        int fineId = -1;
        int ticketId = 0;
    }

    Fine(string code, string description, float fineAmt, int Fineid)
    {
        writeFixedLengthString(offenceCode, code);
        writeFixedLengthString(offenceDescription, description);
        fineAmount = fineAmt;
        fineId = Fineid;
    }

    void addFine(int ticketNumber)
    {
        cout << "Please Enter offence code" << endl;
        getInput(cin, offenceCode);
        cout << "Please Enter offence Discription" << endl;
        getInput(cin, offenceDescription);
        cout << "Please Enter Fine Amount" << endl;
        cin >> fineAmount;
        ticketId = ticketNumber;
        fineId = finesSaved;
        saveFine(fineId);
        finesSaved++;
    }

    // Getter Methods

    string getOffenceCode()
    {
        return offenceCode;
    }

    string getOffenceDescription()
    {
        return offenceDescription;
    }

    int getAmount()
    {
        return fineAmount;
    }

    // Setter methods for Fine
    void setOffenceCode(string code)
    {
        writeFixedLengthString(offenceCode, code);
    }

    void setOffenceDescription(string description)
    {
        writeFixedLengthString(offenceDescription, description);
    }
    void setAmount(float amount)
    {
        fineAmount = amount;
    }

    void displayFine()
    {
        cout << RED << "---------------------" << endl;
        cout << "Fine Ticket Number: " << ticketId << endl;
        cout << "Fine Offence Code: " << offenceCode << endl;
        cout << "Fine Offence Description: " << offenceDescription << endl;
        cout << "Fine Amount: $" << fineAmount << endl;
        cout << "---------------------" << RST << endl;
    }

    void showAll(int ticketID)
    {

        try
        {
            ifstream raFile(filename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot retrieve record");
            }

            for (int index = 0; index < finesSaved; index++)
            {
                raFile.seekg((index) * sizeof(*this));
                raFile.read(reinterpret_cast<char *>(this), sizeof(*this));
                if (ticketId == ticketID)
                {
                    displayFine();
                }
            }
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    void saveFine(int fineId)
    {

        try
        {
            ofstream raFile(filename, ios::binary | ios::app);
            if (raFile.fail())
            {
                throw runtime_error("cannot create database");
            }
            raFile.seekp((fineId) * sizeof(*this));
            raFile.write(reinterpret_cast<const char *>(this), sizeof(*this));
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    void retreiveFine(int fineId)
    {
        try
        {
            fstream raFile(filename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot retrieve record");
            }

            raFile.seekg((fineId) * sizeof(*this));
            raFile.read(reinterpret_cast<char *>(this), sizeof(*this));
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }

    void initialiseList()
    {
        try
        {
            ifstream raFile(filename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot read database");
            }
            else
            {
                Fine a1;

                for (int idx = 0; idx < Maxfines; idx++)
                {
                    raFile.seekg((idx) * sizeof(a1));
                    raFile.read(reinterpret_cast<char *>(&a1), sizeof(a1));

                    if (a1.fineId != -1)
                    {
                        finesSaved++;
                    }
                    a1.fineId = -1;
                }

                cout << "Number of fines saved: " << finesSaved << endl;
                raFile.close();
            }
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
            createBlankRecords();
        }
    }

    void createBlankRecords()
    {
        try
        {
            ofstream raFile(filename, ios::out | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("database cannot be created ");
                for (int idx = 0; idx < Maxfines; idx++)
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
