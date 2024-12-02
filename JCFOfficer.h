// JCFOfficer Class
#include <iostream>
#include <fstream>
#include <string>
#include "Ticket.h"
#include <cstdlib>
#include <iomanip>
#include "Auxillary.h"
#include "User.h"
using namespace std;

class JCFOfficer : public User
{
private:
  int badgenumber;
  char officerName[maxStringsize];
  char assignedStation[maxStringsize];

public:
  // default constructor//
  JCFOfficer()
  {
    badgenumber = 0;
    writeFixedLengthString(officerName, "NameNotSet");
    writeFixedLengthString(assignedStation, "StationNotSet");
  }

  // primary constructor
  JCFOfficer(int bnum, string , string name, string station)
  {
    badgenumber = bnum;
    writeFixedLengthString(officerName, name);
    writeFixedLengthString(assignedStation, station);
  }

  // copy constructor
  JCFOfficer(JCFOfficer &officer)
  {
    badgenumber = officer.badgenumber;
    writeFixedLengthString(officerName,officer.officerName);
    writeFixedLengthString(assignedStation, officer.assignedStation);
  }

  // Setters
  void setBadgeNumber(int bnum)
  {
    if (bnum > 0)
    {
      badgenumber = bnum;
    }
    else
    {
      cout << "Badge number must be greater than 0. Please re-enter a valid number" << endl;
    }
  }

  void setName(const string &fnString)
  {
    writeFixedLengthString(officerName,fnString);
  }


  void setAssignedStation(const string &station)
  {
    writeFixedLengthString(assignedStation, station);
  }




 // Login function
  void Login() override
  {
    try
    {
      // Display JCF Officers login
      cout << "Name: " << officerName << endl;
      cout << "Password: " << badgenumber << endl;
      cout << "\n\t\t +----------------------------+ JCF Officer Login +----------------------------+\n"
           << endl;
      cout << "\t\tPlease enter User Name:\t";
      setUserName(cin);
      cout << "\t\tPlease enter Password:\t";
      setPassword(cin);
   

    
      // Check if entered badge number and password are correct
      if (strcmp(username,officerName)== 0  && getPassword() == badgenumber)
      {
        cout << "Login successful! Welcome, JCF Officer " <<officerName<< endl;
        this->JCFHandler();
        system("pause");
      }
      else
      {
        cout << "Invalid badge number or password. Please try again." << endl;
        system("pause");
      }
    }
    catch (runtime_error &e)
    {
      cerr << e.what() << endl;
      system("cls");
      this->Login(); // Recursively retry login on error
    }
  }

   void JCFHandler(){


  }

  // Add ticket method
  void AddTicket()
  {
    ofstream outTicket{"NewTicket.dat", ios::out};
    if (!outTicket)
    {
      cerr << "Error opening file. Please try again later." << endl;
      return; // Gracefully exit the function without crashing the entire system.
    }
    int ticketnumber;
    cout << "Enter new ticket number (1 to 100, 0 to end input): ";
    cin >> ticketnumber;

    while (ticketnumber > 0 && ticketnumber <= 100)
    {
      Ticket newTicket; // Create object for Ticket class

      // Enter ticket details
      string issueDate, offenceCode, offenceDesc, plateNumber, dueDate, courtDate, issuingOfficer, courtLocation;
      float amount;

      cout << "Enter ticket issue date (YYYY-MM-DD): ";
      cin >> issueDate;
      cout << "Enter offence code: ";
      cin >> offenceCode;
      cout << "Enter offence description: ";
      cin.ignore();
      getline(cin, offenceDesc);
      cout << "Enter license plate number: ";
      cin >> plateNumber;
      cout << "Enter ticket amount: $";
      cin >> amount;
      cout << "Enter due date (YYYY-MM-DD): ";
      cin >> dueDate;
      cout << "Enter court date (YYYY-MM-DD): ";
      cin >> courtDate;
      cout << "Enter issuing officer's name: ";
      cin.ignore();
      getline(cin, issuingOfficer);
      cout << "Enter court location: ";
      getline(cin, courtLocation);

      newTicket.setTicketNumber(ticketnumber);
      newTicket.setTicketIssueDate(issueDate);
      newTicket.setTicketOffenceCode(offenceCode);
      newTicket.setTicketOffenceDescription(offenceDesc);
      newTicket.setLicensePlateNumber(plateNumber);
      newTicket.setTicketAmount(amount);
      newTicket.setDueDate(dueDate);
      newTicket.setCourtDate(courtDate);
      newTicket.setIssuingOfficer(issuingOfficer);
      newTicket.setCourtLocation(courtLocation);

      outTicket.write(reinterpret_cast<const char *>(&newTicket), sizeof(Ticket));
      cout << "Ticket added successfully!" << endl;

      cout << "Enter new ticket number (1 to 100, 0 to end input): ";
      cin >> ticketnumber;
    }

    outTicket.close();
  }

  // Function to view tickets that are due
  void ViewTicketsDue()
  {
    cout << "Viewing tickets that are due..." << endl;
  }

  // Function to view all tickets
  void ViewTickets()
  {

    cout << "Viewing all tickets..." << endl;
  }

  // Function to view outstanding tickets from drivers in each parish
  void TicketsParish()
  {

    cout << "Viewing outstanding tickets in each parish..." << endl;
  }

  // Function to update a ticket
  void updateTicket()
  {
    cout << "Updating ticket..." << endl;

    // obtain the ticket number for ticket update
    int ticketnumber{getTicketNumber("Enter Ticket Number:")};

    // move file-position pointer to correct ticket record to file
    {
      updateFile.seekg((ticketnumber - 1) * sizeof(Ticket));
    }

    // create record object and read first record from file
    Ticket newTicket;
    updateFile.read(reinterpret_cast<char *>(&newTicket), sizeof(Ticket));

    // update ticket record
    if (newTicket.getTicketNumber() != 0)
    {
      outputLine(cout, newTicket); // display the ticket record

      // request the officer to enter new data to display updated ticket report
      cout << "Enter ticket issue date (YYYY-MM-DD): ";
       cin >> issueDate;

      cout << "Enter offence code: " cin >> offenceCode;

      cout << "Enter offence description: " cin.ignore();
      getline(cin, offenceDesc);

      cout << "Enter license plate number: " cin >> plateNumber;

      cout << "Enter ticket amount: $" cin >> amount;

      cout << "Enter due date (YYYY-MM-DD): " cin >> dueDate;

      cout << "Enter court date (YYYY-MM-DD): " cin >> courtDate;

      cout << "Enter issuing officer's name: " cin.ignore();
      getline(cin, issuingOfficer);

      cout << "Enter court location: " getline(cin, courtLocation);

      newTicket.setTicketNumber(ticketnumber);
      newTicket.setTicketIssueDate(issueDate);
      newTicket.setTicketOffenceCode(offenceCode);
      newTicket.setTicketOffenceDescription(offenceDesc);
      newTicket.setLicensePlateNumber(plateNumber);
      newTicket.setTicketAmount(amount);
      newTicket.setDueDate(dueDate);
      newTicket.setCourtDate(courtDate);
      newTicket.setIssuingOfficer(issuingOfficer);
      newTicket.setCourtLocation(courtLocation);

      // move file-position pointer to correct ticket record in file
      {
        updateFile.seekp((ticketnumber - 1) * sizeof(Ticket));
      }

      // write updated record over old record in file
      updateFile.write(reinterpret_cast<const_cast *>(&newTicket), sizeof(Ticket));
      cout << "Ticket updated successfully!" << endl;
    }
    else
    {
      // display error if ticket does not show up
      cerr << "Ticket Number: " << ticketnumber << "has no information." << endl
    }
  }
}

// Function to view Warrant details of each driver
void
CheckWarrantStatus()
{

  cout << "Checking warrant status..." << endl;
}

void deleteTicket()
{
  // obtain the ticket number for ticket update
  int ticketnumber{getTicketNumber("Enter Ticket to delete:")};

  // move file-position pointer to correct ticket record to file
  {
    deleteFromFile.seekg((ticketnumber - 1) * sizeof(Ticket));
  }

  // create record object and read first record from file
  Ticket newTicket;
  deleteFromFile.read(reinterpret_cast<char *>(&newTicket), sizeof(Ticket));

  // delete record, if record exists in file
  if (newTicket.getTicketNumber() != 0)
  {
    Ticket blankticket; // create blank record
    // move file-position pointer to correct ticket record in file
    {
      deleteFromFile.seekp((ticketnumber - 1) * sizeof(Ticket));
    }
    // replacing existing ticket record with blank record
    updateFile.write(reinterpret_cast<const_cast *>(&newTicket), sizeof(Ticket));
    cout << "Ticket deleted successfully!" << endl;

    cout << "Ticket Number: " << ticketnumber << "deleted.\n";
  }
  else
  {
    // display error if ticket does not exist
    cerr << "Ticket Number: " << ticketnumber << "is empty.\n"
         << endl;
  }
};

/*





     // Function for adding new ticket
    void AddTicket(const string &stringNewTicket)
    {
        ofstream outTicket{"NewTicket.dat", ios::out | ios::binary};

        // Exit program if output stream could not open file
        if (!outTicket)
        {
            cerr << "File could not be opened!" << endl;
            exit(EXIT_FAILURE);
        }

        // Output required number of blank records to file
        for (int t = 0; t < 100; ++t)
        {
            Ticket blankTicket;  // Constructor eliminates each data member
            outTicket.write(reinterpret_cast<const char *>(&blankTicket), sizeof(JCFOfficer));
        }

        fstream inOutTicket{"NewTicket.dat", ios::in | ios::out | ios::binary};

        cout << "Enter new ticket number (1 to 100, 0 to end input)\n";

        int ticketnumber
        cin >> ticketnumber; //read ticket number


    // officer enters information which is copied into file
    while (ticketnumber > 0 && ticketnumber <= 100)
    {

       officer enters ticket information
       cout <<"";
       cin >>
       cin >>
       cin >>


      // create object for Ticketclass
      JCFOfficer newticket{};

      // seek position in the file of user specified record
      /* outTicket.seekp((newticket.getTicketNumber() - 1) * sizeof(JCFOfficer)); */

// write user-specified information in file
/*outTicket.write(reinterpret_cast<const char*>(&blankTickets), sizeof(JCFOfficer));
}
}
// Function to display the tickets that are due
void ViewTicketsDue()
{
}
// Function to view tickets
void ViewTickets()
{
}
// Function to view outstanding tickets from driver in each parish
void TicketsParish()
{
}
// Function to update ticket
void updateTicket()
{
}
// Function to view Warrant details of each driver
void CheckWarrantStatus()
{
}
};
*/
