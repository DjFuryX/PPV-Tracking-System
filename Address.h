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
        writeFixedLengthString(street,"notSet");
        writeFixedLengthString(city,"notSet");
        writeFixedLengthString(parish,"notSet");

    }

     Address(string newStreet, string newCity, string newParish)
    {
       writeFixedLengthString(street,newStreet);
       writeFixedLengthString(city,newCity);
       writeFixedLengthString(parish,newParish);
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

