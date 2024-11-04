// Vehicle Class
#include <iostream>
using namespace std;

#ifndef MYHEADEFILE_H
#define MYHEADEFILE_H

class Vehicle
{
private:
    string currentDriver;
    string currentOwner;
    string previousDriver;
    string PreviousOwner;
    string licensePlateNumber;

public:
    Vehicle() // default Constructor
    {
        currentDriver = "notSet";
        currentOwner = "notSet";
        previousDriver = "notSet";
        PreviousOwner = "notSet";
        licensePlateNumber = "AA-0000";
    }

    /// @brief Creates a vehicle object
    /// @param curr_driver current driver of vehicle
    /// @param prev_driver previous driver of vehicle
    /// @param curr_owner current owner of vehicle
    /// @param prev_owner previous owner of vehicle
    /// @param plateNumber License plate number of vehicle
    Vehicle(string plateNumber, string curr_driver, string prev_driver, string curr_owner, string prev_owner)
    {
        licensePlateNumber = plateNumber;
        currentDriver = curr_driver;
        currentOwner = curr_owner;
        previousDriver = prev_driver;
        PreviousOwner = prev_owner;
    }

    string getCurrentDriver()
    {

        return currentDriver;
    }

    string getPreviousDriver()
    {

        return previousDriver;
    }
};

#endif