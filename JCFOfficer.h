// JCFOfficer Class
#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
#include "Driver.h"
#include "Auxillary.h"
using namespace std;

#ifndef JCFOfficer_H
#define JCFOfficer_H

class JCFOfficer : public User
{
private:
  int badgenumber;
  char officerName[maxStringsize];
  char assignedStation[maxStringsize];
  char stationParish[maxStringsize];

public:
  // default constructor//
  JCFOfficer()
  {
    badgenumber = 0;
    writeFixedLengthString(officerName, "NameNotSet");
    writeFixedLengthString(assignedStation, "StationNotSet");
    writeFixedLengthString(stationParish, "StationNotSet");
  }

  // primary constructor
  JCFOfficer(int bnum, string name, string station, string officerParish)
  {
    badgenumber = bnum;
    writeFixedLengthString(officerName, name);
    writeFixedLengthString(assignedStation, station);
    writeFixedLengthString(stationParish, officerParish);
  }

  // copy constructor
  JCFOfficer(JCFOfficer &officer)
  {
    badgenumber = officer.badgenumber;
    writeFixedLengthString(officerName, officer.officerName);
    writeFixedLengthString(assignedStation, officer.assignedStation);
    writeFixedLengthString(stationParish, officer.stationParish);
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
    writeFixedLengthString(officerName, fnString);
  }

  void setAssignedStation(const string &station)
  {
    writeFixedLengthString(assignedStation, station);
  }

  void setStationParish(const string &parish)
  {
    writeFixedLengthString(stationParish, parish);
  }

  // Getters
  string getOfficerName()
  {

    return officerName;
  }

  string getOfficerStation()
  {

    return assignedStation;
  }
  // added
  int getBadgeNumber()
  {
    return badgenumber;
  }
  string getStationParish()
  {
    return stationParish;
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
      if (strcmp(username, officerName) == 0 && getPassword() == badgenumber)
      {
        cout << "Login successful! Welcome, JCF Officer " << officerName << endl;

        this->JCFHandler();
      }
      else
      {
        cout << "Invalid badge number or password. Please try again." << endl;
      }
    }
    catch (runtime_error &e)
    {
      cerr << e.what() << endl;
      system("cls");
      this->Login(); // Recursively retry login on error
    }
  }

  void JCFHandler()
  {
    Ticket *ticket = new Ticket();
    int option = showMenu(); // get user option

    while (option != 0)
    { // Start while loop for main menu

      switch (option)
      { // case structure is used to determine option selected
      case 1:
        issueTicket();
        break;
      case 2:
        updateTicket(ticket);
        break;
      case 3:
        cout << "Viewing All tickets that are due..." << endl;
        ticket->showAllTickets("warrant outstanding");
        break;
      case 4:
        ticketsParish();
        break;
      case 5:
        ticketsDueByDriver(ticket);
        break;
      case 6:
        cout << "Viewing all tickets..." << endl;
        ticket->showAllTickets();
        break;
      default: // if an invalid number is entered
        cout << "Invalid option chosen" << endl;
        break;
      } // end switch case
      system("pause");
      option = showMenu(); // get user option
    }
  }

  int showMenu()
  {
    int choice;
    // Get current date and time
    time_t timestamp;
    time(&timestamp);
    system("cls");                                 // clears the screen
    cout << "Date: " << ctime(&timestamp) << endl; // print current date and time
    /*prints a menu so the user can select their desired choice*/
    cout << "\n\t\t +------------------------+ JCF Officer Menu +----------------------+" << endl;
    cout << "  \t\t | " CYN "1." RST "  Issue Ticket                                                 |" << endl;
    cout << "\n\t\t | " CYN "2." RST "  Update Ticket                                                |" << endl;
    cout << "\n\t\t | " CYN "3." RST "  View Tickets Due                                             |" << endl;
    cout << "\n\t\t | " CYN "4." RST "  View Tickets Parish                                          |" << endl;
    cout << "\n\t\t | " CYN "5." RST "  Check Warrant Status                                         |" << endl;
    cout << "\n\t\t | " CYN "6." RST "  Show All Tickets                                             |" << endl;
    cout << "\n\t\t | " CYN "0." RST "  Exit                                                         |" << endl;
    cout << "\t\t +------------------------------------------------------------------+" << endl;
    cout << "\nPlease select with the " CYN "digits" RST " on the left:  " << endl; // prompts for user choice
    cin >> choice;
    system("cls");
    // clears the screen
    return choice;
  }

  void issueTicket()
  {

    Driver driver;
    Ticket newTicket;

    int Userinput;

    cout << "Enter the drivers Tax Registration Number: " << endl;
    cin >> Userinput;

    int id = driver.findTrn(Userinput);

    if (id == -1)
    {
      cout << "User not Found" << endl;
    }
    else
    {
      cout << "User Found" << endl;
      driver.retrieveDriver(id);
      newTicket.createTicket(badgenumber, officerName, assignedStation, stationParish, driver.GetTrn());
    }
  }

  void updateTicket(Ticket *ticket)
  {
    Driver *driver = new Driver;
    int drivertrn;

    cout << "Please Enter Drivers Trn: " << endl;
    cin >> drivertrn;

    if (driver->findTrn(drivertrn) != -1)
    {

      ticket->updateTicket(drivertrn);
    }
    else
    {

      cout << "Driver trn was not found" << endl;
    }
  }

  void ticketsDueByDriver(Ticket *ticket)
  {
    int trn;
    cout << "Please enter trn of Driver" << endl;
    cin >> trn;
    ticket->showAllTickets(trn, "warrant outstanding");
  }

  // Function to view outstanding tickets from drivers in each parish
  void ticketsParish()
  {
    Driver *driver = new Driver();
    char ticketParish[maxStringsize];
    cout << "Please Enter Parish Name" << endl;
    getInput(cin, ticketParish);

    cout << "---------------Tickets in " << ticketParish << "--------------------" << endl;
    driver->showAllDrivers(ticketParish);
  }

  void initialiseList() override {};
};

#endif // JCFOfficer.h