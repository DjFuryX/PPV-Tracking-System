// Driver Class
#include <iostream>

using namespace std;

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