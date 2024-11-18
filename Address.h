// Driver Class
#include <iostream>
#include <string.h>
using namespace std;

class Address
{
private:
    string street;
    string city;
    string parish;
    int MaxstringSize = 50;

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
        cout << "Street: ";
        cin >> street;
        cout << "city: ";
        cin >> city;
        cout << "parish: ";
        cin >> parish;
    }

    void Display()
    {
        cout << "Street: " << street << endl;
        cout << "city: " << city << endl;
        cout << "parish: " << parish << endl;
    }

  

};

// Overrides How the objects of this class are stored as string
ostream &operator<<(ostream &out, Address &c)
{
    out << "Street: " << c.GetStreet() << "city: " << c.GetCity() << "parish: " << c.GetParish();
    return out;
}