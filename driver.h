// Driver Class
#include <stdexcept>  
#include <string>
#include <vector>
#include "Applicant.h"
#include "User.h"
#include "Ticket.h"

using namespace std;

class Driver: public Applicant, public User
{

private:
    vector<Ticket> tickets; // List of tickets the driver has
    int trn;  // Driver's TRN 
    string name;  // Driver's name
    string emailAddr;  // Driver's email address

public:
    Driver()
    {
        trn = 0;
        name = "not Set";
        emailAddr = "NotSet@email.com";
    }

    Driver(int trn, string driverName, string email, time_t dateOfBirth, string street, string city, string parish)
    {
        this->trn = trn;
        name = driverName;
        emailAddr = email;
    }

    void display()
    {
        cout << "Trn: " << trn << endl;
        cout << "Name:" << name << endl;
        cout << "Email Address:" << emailAddr << endl;
        cout << "----------------------------" << endl;
        currAddr.Display();
        cout << "----------------------------" << endl;
      
    }



    void Login() 
    {
        try
        {
            // Display Driver's login prompt
            cout << "\n\t\t +----------------------------+ Driver Login +----------------------------+\n" << endl;
            cout << "\t\tPlease enter TRN:\t";
            int enteredTRN;
            cin >> enteredTRN;  // Input the TRN

            cout << "\t\tPlease enter Password:\t";
            int enteredPassword;  // Password as an integer
            cin >> enteredPassword;  // Input the password

            if (enteredTRN <= 0 || enteredPassword <= 0)
            {
                throw runtime_error("Invalid TRN or password. Please try again.");
            }

            // Check if entered TRN and password are correct
            if (enteredTRN == trn && enteredPassword == getPassword())
            {
                cout << "Login successful! Welcome, Driver " << name << "." << endl;
                // You can add additional functionality here (e.g., viewing tickets, fines, etc.)
                system("pause");
            }
            else
            {
                cout << "Invalid TRN or password. Please try again." << endl;
                system("pause");
            }
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
            system("cls");
            this->Login();  
        }
    }

    // Getter for TRN
    int getTrn() const
    {
        return trn;
    }

    // Setter for TRN
    void setTrn(int trn)
    {
        if (trn > 0)
        {
            this->trn = trn;
        }
        else
        {
            cout << "TRN must be greater than 0. Please re-enter a valid TRN" << endl;
        }
    }


};




/*int main() {
    Driver driver(12345678, "John Doe", "john.doe@email.com");

    // Assuming password is set somewhere else, e.g., via User class
    // Let's assume for testing, we set the password directly
    driver.setPassword(1234);  // Assume 1234 is the password set for the driver

    // Call login function
    driver.Login();  // This will prompt for TRN and password and attempt to login

    return 0;
}*/