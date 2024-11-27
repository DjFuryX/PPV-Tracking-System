// Driver Class
#include <iostream>
#include <string.h>
#include "Auxillary.h"
using namespace std;

#ifndef Address_H
#define Address_H

class Address
{
private:
    char street[50];
    char city[50];
    char parish[50];
public:
    Address()
    {
        writeFixedLengthString(street,50,"notSet");
        writeFixedLengthString(city,50,"notSet");
        writeFixedLengthString(parish,50,"notSet");

    }

     Address(string newStreet, string newCity, string newParish)
    {
       writeFixedLengthString(street,50,newStreet);
       writeFixedLengthString(city,50,newCity);
       writeFixedLengthString(parish,50,newParish);
    } 

    string GetStreet()
    {
        return street;
    }

    string GetCity()
    {
        return city;
    }

    string GetParish()
    {
        return parish;
    }

    void setStreet(){

        cout << "Street: "<<endl;
        getInput(cin,street);
    }

    void setCity(){

        cout << "city: "<<endl;
        getInput(cin,city);
    }

    void setParish(){
        cout << "parish: "<<endl;
        getInput(cin,parish); 
    }

    void SetAdrress()
    {
        setStreet();
        setCity();
        setParish();
    }

    void Display()
    {
        cout << "Street: " << street << endl;
        cout << "city: " << city << endl;
        cout << "parish: " << parish << endl;
    }
};
#endif

