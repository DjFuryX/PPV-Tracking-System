// Main function

#include <iostream>
#include "ProcessOfficer.h"
#include"User.h"
#include"Driver.h"
//#include"JCFOfficer.h"
using namespace std;

int main()
{
    User *userPtr = nullptr;
    Applicant *applicant=new Applicant();
    applicant->initialiseApplicantList();
    cout << "Applications Saved: " << numApplicationSaved << endl;

    /*int option = 0;  // Initialize option to 0 (safe default value)

    // You need to initialize userPtr before calling ShowMenu()
    option = userPtr != nullptr ? userPtr->ShowMenu() : 0; // get user option (only call ShowMenu if userPtr is valid)*/
    
    int option = userPtr->User::ShowMenu(); // get user option
    while (option != 0)
    { // Start while loop for main menu

        switch (option)
        { // case structure is used to determine option selected
        case 1:
            userPtr = new Driver(12345, 6543210, "John", "Traffic Violation", "john.doe@example.com", 540); // Provide Service to Driver
            userPtr->Login();
            break;
        case 2:
             // UserPtr= new JCFOfficer();// Provide Service to JCF officeruser

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
