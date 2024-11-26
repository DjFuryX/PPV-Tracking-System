// ProcessOfficer Class
#include "User.h"
#include "Applicant.h"

#ifndef ProcessOfficer_H
#define ProcessOfficer_H

 string msg;

class ProcessOfficer : public User
{
private:
    int officerId;
    string officerName;
    string asssignedStation;
   

public:
    ProcessOfficer()
    {
        officerId = 100;
        officerName = "ProcessOfficer";
        asssignedStation = "NoAssignedStation";
    }
    ProcessOfficer(int id, string officerName, string stationName)
    {
        officerId = id;
        officerName = officerName;
        asssignedStation = stationName;
    }

    bool Login()
    {
       


      try {

        cout << "\n\t\t +--------------------------------+ Process Officer Login +--------------------------------+\n" << endl;
        cout <<"\t\t"<< msg<<endl;
        cout << "\t\tPlease enter Username:\t";
        setUserName(cin);
        cout << "\t\tPlease enter Password\t";
        setPassword(cin);

      }
        
  catch (runtime_error &e)
        {
            cerr << e.what() << endl;

            msg=e.what();
            system("cls");  
            this->Login();
            
        }
        msg="";
        return true;
    }

    int ShowMenu()
    {

        int choice;
        // Get current date and time
        time_t timestamp;
        time(&timestamp);
        system("cls");                                 // clears the screen
        cout << "Date: " << ctime(&timestamp) << endl; // print current date and time
        /*prints a menu so the user can select their desired choice*/
        cout << "\n\t\t +--------------------------------+ Process Officer Menu +--------------------------------+" << endl;
        cout << "\t\t | " CYN "1." RST "    Applicant                                                              |" << endl;
        cout << "\n\t\t | " CYN "2." RST "    Driver                                                               |" << endl;
        cout << "\n\t\t | " CYN "0." RST "    Exit                                                                 |" << endl;
        cout << "\t\t +---------------------------------------------------------------------------------+" << endl;
        cout << "\nPlease select with the " CYN "digits" RST " on the left:  " << endl; // prompts for user choice
        cin >> choice;
        system("cls");

        



        return choice;
        // clears the screen
    }
};

#endif