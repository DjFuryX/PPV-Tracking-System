// Driver Class
#include <iostream>
#include <string.h>
using namespace std;

#ifndef Address_H
#define Adress_H

class Address
{
private:
    string street;
    string city;
    string parish;
public:
    Address()
    {
        street = "Notset";
        city = "Notset";
        parish = "NotSet";
    }

    Address(string street, string city, string parish)
    {
        this->street = street;
        this->city = city;
        this->parish = parish;
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

    void SetAdrress()
    {
        cout << "Street: "<<endl;
        cin >> street;
        cout << "city: "<<endl;
        cin >> city;
        cout << "parish: "<<endl;
        cin >> parish; 
    }

    void Display()
    {
        cout << "Street: " << street << endl;
        cout << "city: " << city << endl;
        cout << "parish: " << parish << endl;
    }

  

};

#endif

// Overrides How the objects of this class are stored as string
ostream &operator<<(ostream &out, Address &c)
{
    out << "Street: " << c.GetStreet() << "city: " << c.GetCity() << "parish: " << c.GetParish();
    return out;
}