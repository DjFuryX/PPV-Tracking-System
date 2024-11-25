// JCF_Officer Class
#include <iostream>
using namespace std;

class JCF_Officer
{

private:
  int badgenumber;
  string firstname;
  string lastname;
  string assignedStation;

public:
  // default constructor//
  JCF_Officer()
  {
    badgenumber = 0;
    firstname = "";
    lastname = "";
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

  //Setters
   void setBadgeNumber(int bnum)
    {
      badgenumber = bnum;
    }

    void setFirstName(const string &fn)
    {
      firstname = fn;
    }

    void setLastName(const string &ln)
    {
      lastname = ln;
    }

    void setAssignedStation(const string &station)
    {
      assignedStation = station;
    }

     //Getters
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
  void AddTicket()
  {
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

