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
    int Id;
    int ticketId;

public:
    // Default Constructor
    Fine()
    {
        writeFixedLengthString(offenceCode, "Notset");
        writeFixedLengthString(offenceDescription, "notSet");
        fineAmount = 0.0;
        int Id = -1;
        int ticketId=0;
    }

    Fine(string code, string description, float fineAmt, int Fineid)
    {
        writeFixedLengthString(offenceCode, code);
        writeFixedLengthString(offenceDescription, description);
        fineAmount = fineAmt;
        Id = Fineid;
    }

    void addFine(int ticketNumber)
    {
        cout << "Please Enter offence code" << endl;
        getInput(cin, offenceCode);
        cout << "Please Enter offence Discription" << endl;
        getInput(cin, offenceDescription);
        cout << "Please Enter Fine Amount" << endl;
        cin >> fineAmount;
        ticketId=ticketNumber;
        Id = finesSaved;
        saveFine(Id);
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

    void displayFine(Fine fine)
    {
        cout << "Fine Offence Code: " << fine.offenceCode << endl;
        cout << "Fine Offence Description: " << fine.offenceDescription << endl;
        cout << "Fine Fine Amount: $" << fine.fineAmount << endl;
    }


    float showAll(int ticketID){
        Fine record;

        float total=0;

         try
        {
            fstream raFile(filename, ios::in | ios::binary);
            if (raFile.fail())
            {
                throw runtime_error("cannot retrieve record");
            }

            for(int index=0;index<finesSaved;index++){
                raFile.seekg((index) * sizeof(Fine));
                raFile.read(reinterpret_cast<char *>(&record), sizeof(Fine));
                displayFine(record);
            }

          
            raFile.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
        return total;
    }

    void saveFine(int fineId)
    {

        try
        {
            // ofstream raFile(driverFilename, ios::binary | ios::app);
            ofstream raFile(filename, ios::binary | ios::out);
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

                    if (a1.Id != -1)
                    {
                        finesSaved++;
                    }
                    a1.Id = -1;
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

/*Link to Ticket Method
it created a linkage between fine and ticket
such copying or getting the offense code and description and
fine amount from the ticket object to fine object


so it pretty much allows the fine to accurately reflect violation details
from the ticket useful when fine is issued directly based on a ticket offense */

/*Main to Test
    #include <iostream>
    #include <string.h>
    sing namespace std;

    #include <Ticket.h>
    #include <Fine.h>

    int main() {
    // Creating a Ticket instance
    Ticket ticket(12345, "2024-11-01", "1001", "Speeding", "AB-1234", 15000.0,
                  "2024-11-30", "2024-12-15", "Officer Smith", "Spanish Town Court");

    // Fine instance that link it to the Ticket
    Fine fine;
    fine.linkToTicket(ticket);

    // Displaying ticket and fine information
    cout << "Ticket Report:" << endl;
    ticket.viewTicketReport();
    cout << "\nFine Details:" << endl;
    fine.displayFine();

    return 0;
}*/