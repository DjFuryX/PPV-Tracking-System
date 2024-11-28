// JCF_Officer Class
#include <iostream>
#include <fstream>
#include <string>
#include "Auxillary.h"
#include "User.h" 
using namespace std;

class JCF_Officer : public User
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
        assignedStation = station;
    }

  // copy constructor
  JCF_Officer(JCF_Officer &officer)
  {
    badgenumber = officer.badgenumber;
    firstname = officer.firstname;
    lastname = officer.lastname;
    assignedStation = officer.assignedStation;
  }

  // Login function
    void Login() override
    {
        try
        {
            // Display JCF Officers login
            cout << "\n\t\t +----------------------------+ JCF Officer Login +----------------------------+\n" << endl;
            cout << "\t\tPlease enter Badge Number:\t";
            int enteredBadgeNumber;
            cin >> enteredBadgeNumber;  // Input the badge number

            cout << "\t\tPlease enter Password:\t";
            int enteredPassword;  // Password as integer
            cin >> enteredPassword;   // Input the password

            if (enteredBadgeNumber <= 0 || enteredPassword <= 0)
            {
                throw runtime_error("Invalid badge number or password. Please try again.");
            }

            // Check if entered badge number and password are correct
            if (enteredBadgeNumber == badgenumber && enteredPassword == getPassword())
            {
                cout << "Login successful! Welcome, JCF Officer " << firstname << " " << lastname << "." << endl;
                this->processOfficerHandler();
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
            this->Login();  // Recursively retry login on error
        }
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
    
    // copy at most 35 characters from string to firstname
  void setFirstName(const string &fnString)
    {
        size_t length = fnString.size();
        length = (length < 35 ? length : 34);
        fnString.copy(firstname, length);
        firstname[length] = '\0';  // Null-terminate the string
    }

  void setLastName(const string &lnString)
  {
    // copy at most 35 characters from string to lastname
    size_t length = lnString.size();
      length = (length < 35 ? length : 34);
      lnString.copy(lastname, length);
      lastname[length] = '\0'; // append null character to firstname
  }

  void setAssignedStation(const string &station)
  {
    assignedStation = station;
  }


  // Add ticket method
    void AddTicket() {
        ofstream outTicket{"NewTicket.dat", ios::out};
        if (!outTicket) {
          cerr << "Error opening file. Please try again later." << endl;
          return;  // Gracefully exit the function without crashing the entire system.
        }
        int ticketnumber;
        cout << "Enter new ticket number (1 to 100, 0 to end input): ";
        cin >> ticketnumber;

        while (ticketnumber > 0 && ticketnumber <= 100) {
            Ticket newTicket;  // Create object for Ticket class

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

            outTicket.write(reinterpret_cast<const char*>(&newTicket), sizeof(Ticket));
            cout << "Ticket added successfully!" << endl;

            cout << "Enter new ticket number (1 to 100, 0 to end input): ";
            cin >> ticketnumber;
        }

        outTicket.close();
    }

    // Function to view tickets that are due
    void ViewTicketsDue()
    {
        /
        
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
    }

    // Function to view Warrant details of each driver
    void CheckWarrantStatus()
    {
       
        cout << "Checking warrant status..." << endl;
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
            outTicket.write(reinterpret_cast<const char *>(&blankTicket), sizeof(JCF_Officer));
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
      JCF_Officer newticket{};

      // seek position in the file of user specified record
      /* outTicket.seekp((newticket.getTicketNumber() - 1) * sizeof(JCF_Officer)); */

      // write user-specified information in file
      /*outTicket.write(reinterpret_cast<const char*>(&blankTickets), sizeof(JCF_Officer)); 
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