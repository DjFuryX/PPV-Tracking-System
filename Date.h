#include <iostream>
#include <time.h>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
    // time_t fdate;

public:
    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }

    Date(int dy, int mnth, int yr)
    {
        day = dy;
        month = mnth;
        year = yr;
    }

    void SetDob()
    {
        cout << "day: ";
        cin >> day;
        cout << "month: ";
        cin >> month;
        cout << "year: ";
        cin >> year;
    }

    int GetDay()
    {
        return day;
    }

    int GetMonth()
    {
        return month;
    }

    int GetYear()
    {
        return year;
    }

    void SetDay(int dy)
    {
        day = dy;
    }

    void SetMonth(int mnth)
    {
        month = mnth;
    }

    void SetYear(int yr)
    {
        year = yr;
    }

    void Display()
    {
        cout << day << "/" << month << "/" << year<<endl;

        //  cout << ctime(&fdate) << endl;
    }
};