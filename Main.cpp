// Main function

#include <iostream>
#include "ProcessOfficer.h"
using namespace std;

User *UserPtr;

int main()
{

   int option = UserPtr->User::ShowMenu();// get Main menu

    while (option != 0)
    { // Start while loop for main menu

        switch (option)
        { // case structure is used to determine option selected
        case 1:
            cout << "Provide service to Driver" << endl; // Provide Service to Driver

            break;
        case 2:
            cout << "Provide service to JCF Officer" << endl; // Provide Service to JCF officer
            

            break;
        case 3:
            UserPtr = new ProcessOfficer();
           

            break;
        default: // if an invalid number is entered
            cout << "Invalid option chosen" << endl;
            break;
        } // end switch case

        if (UserPtr->Login()){

         UserPtr->ShowMenu();

        }
     


        option = UserPtr->User::ShowMenu(); // get user option
    }
    printf("\n\nGoodbye\nClosing application......."); // closing message
    return 0;                                          // 0 indicates that the program terminated successfully
}


