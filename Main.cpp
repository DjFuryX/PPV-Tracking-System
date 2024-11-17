// Main function

#include <iostream>
#include "Applicant.h"
using namespace std;

void CreateBlankRecords(string, int, Applicant);

int main()
{
    string filename="ApplicationList";

    Applicant a1;
    Applicant a2;

    CreateBlankRecords(filename,500,a2);

   

   // a1.Display();
    cout<<a2<<endl;// a2.CreateApplication();
    a2.CreateApplication();

    cout << "------------------------------------------------";
    cout<<a2<<endl;

   // a2.SaveApplication();


    return 0;
}


void  CreateBlankRecords(string filename, int maxRecords, Applicant blank)
    {
        try
        {
            ofstream file(filename, ios::out | ios::binary);
            if (file.fail())
            {
                throw runtime_error("Exception: Initializing database!");
            }
            for (int i = 0; i < maxRecords; i++)
            {
                file.seekp(i * sizeof(blank));
                file.write(reinterpret_cast<const char *>(&blank), sizeof(blank));
            }
            file.close();
        }
        catch (runtime_error &e)
        {
            cerr << e.what() << endl;
        }
    }