// JCF_Officer Class
#include <iostream>
#include "Auxillary.h"
#include "User.h"
using namespace std;

class JCF_Officer
{
private:
  int badgenumber;
  char firstname[35];
  char lastname[35];
  string assignedStation;

public:
  // default constructor//
  JCF_Officer()
  {
    badgenumber = 0;
    writeFixedLengthString(firstname, "NameNotSet");
    writeFixedLengthString(lastname, "NameNotSet");
    assignedStation = "";
  }

  // primary constructor
  JCF_Officer(int bnum, string fn, string ln, string station)
  {
    badgenumber = bnum;
    firstname = fn;
    lastname = ln;
    station = assignedStation;
  }

  // copy constructor
  JCF_Officer(JCF_Officer &officer)
  {
    badgenumber = officer.badgenumber;
    firstname = officer.firstname;
    lastname = officer.lastname;
    assignedStation = officer.assignedStation;
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

  void setFirstName(const string &fnString)
  {
    // copy at most 35 characters from string to firstname
    size_t length{fnString.size()};
    length = (length < 35 ? length : 34);
    fnString.copy(firstname, length);
    firstname[length] = '\0'; // append null character to firstname
  }

  void setLastName(const string &lnString)
  {
    // copy at most 35 characters from string to lastname
    size_t length{lnString.size()};
    length = (length < 35 ? length : 34);
    lnString.copy(lastname, length);
    lastname[length] = '\0'; // append null character to firstname
  }

  void setAssignedStation(const string &station)
  {
    assignedStation = station;
  }

  // Getters
  int getBadgeNumber() const
  {
    return bnum;
  }

  string getFirstName() const
  {
    return fn;
  }

  string getLastName() const
  {
    return ln;
  }

  string getAssignedStation() const
  {
    return station;
  }

  // Function for adding new ticket
  void AddTicket(const string &stringNewTicket)
  {
    ofstream outTicket{"NewTicket.dat", ios::out | ios::binary};

    // exit program if output stream could not open file
    if (!outTicket)
    {
      cerr << "File could not be opened!" << endl;
      exit(EXIT_FAILURE);
    }

    Jcf_Officer blankTicket; // constructor eliminates each data member

    // output required number of blank records to file
    for (int t = 0; t < 100; ++t)
    {
      outTicket.write(reinterpret_cast<const char *>(&blankTickets), sizeof(JCF_Officer));
    }

    fstream outTicket{"NewTicket.dat", ios::in | ios::out | ios::binary};

    cout << "Enter new ticket number (1 to 100, 0 to end input)\n";

    /*int ticketnumber
   cin >> ticketnumber; //read ticket number
   */

    // officer enters information which is copied into file
    while (ticketnumber > 0 && ticketnumber <= 100)
    {
      /*
       officer enters ticket information
       cout <<"";
       cin >>
       cin >>
       cin >>
      */

      // create object for Ticketclass
      JCF_Officer newticket{};

      // seek position in the file of user specified record
      /* outTicket.seekp((newticket.getTicketNumber() - 1) * sizeof(JCF_Officer)); */

      // write user-specified information in file
      /*outTicket.write(reinterpret_cast<const char*>(&blankTickets), sizeof(JCF_Officer)); */
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
