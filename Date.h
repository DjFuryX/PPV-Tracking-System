#include <iostream>
using namespace std;


#ifndef Date_H
#define Date_H

class Date
{
private:
    int day;
    int month;
    int year;
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

    void setDate()
    {
        cout << "day: "<<endl;

        cin >> day;
        cout << "month: "<<endl;
        cin >> month;
        cout << "year: "<<endl;
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
    }

    int daysToDueDate(Date date){
        int currenttotalDays=this->GetDay()+this->GetMonth()*28+this->GetYear()*365;
        int dueTotalDays=date.GetDay()+date.GetMonth()*28+date.GetYear()*365;
        int daysleft=currenttotalDays-dueTotalDays;

        cout<<"Days to due date"<<daysleft<<endl;
        return daysleft;
    }
};

//Overrides How the objects of this class are stored as string
ostream &operator<<(ostream &out, Date &c)
{
    out << c.GetDay() << "/" << c.GetMonth() << "/" << c.GetYear()<<endl;
    return out;
}

#endif

