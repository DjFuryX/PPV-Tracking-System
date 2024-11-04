// Vehicle Class
#include <iostream>
using namespace std;

#ifndef MYHEADEFILE_H
#define MYHEADEFILE_H

class Vehicle
{
private:
    string curentDriver;
    string currentOwner;
    string previousDriver;
    string PreviousOwner;
    int licensePlateNumber;

public:
    Vehicle() // default Constructor
    {
        curentDriver = "notSet";
        currentOwner = "notSet";
        previousDriver = "notSet";
        PreviousOwner = "notSet";
        licensePlateNumber = 0;
    }

    /// @brief Create a vehicle object
    /// @param curr_driver current driver of vehicle
    /// @param prev_driver previous driver of vehicle
    /// @param curr_owner current owner of vehicle
    /// @param prev_owner previous owner of vehicle
    /// @param plateNumber License plate number of vehicle
    Vehicle(int plateNumber,string curr_driver, string prev_driver, string curr_owner, string prev_owner)
    {

        curentDriver =curr_driver;
        currentOwner = curr_owner;
        previousDriver = prev_driver;
        PreviousOwner = prev_owner;
        licensePlateNumber = 0;
    }
};

#endif