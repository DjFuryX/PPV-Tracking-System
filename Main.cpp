// Main function

#include <iostream>
#include "ProcessOfficer.h"
using namespace std;

int main()
{
    User *userPtr;
    Applicant *applicant=new Applicant();
    applicant->initialiseApplicantList();
    
    cout << "Applications Saved: " << numApplicationSaved << endl;
    applicant->retrieveApplication(100);
    applicant->Display();
    applicant->DeleteApplication();
    applicant->Display();
   

    cout << "Applications Saved: " << numApplicationSaved << endl;

    system("pause");

    int option = userPtr->User::ShowMenu(); // get user option

    while (option != 0)
    { // Start while loop for main menu

        switch (option)
        { // case structure is used to determine option selected
        case 1:
            //  UserPtr = new Driver(); // Provide Service to Driver

            break;
        case 2:
            //   UserPtr= new JCFOfficer();// Provide Service to JCF officeruser

            break;
        case 3:
            userPtr = new ProcessOfficer(240, "Norman", "Ramble Police Station");
            userPtr->Login();
            break;
        default: // if an invalid number is entered
            cout << "Invalid option chosen" << endl;
            break;
        } // end switch case
        system("pause");
        option = userPtr->User::ShowMenu(); // get user option
    }
    cout << "\n\nGoodbye\nClosing application......." << endl; // closing message
    return 0;                                                  // 0 indicates that the program terminated successfully
}
