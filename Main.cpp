// Main function

#include <iostream>
#include "Applicant.h"
using namespace std;

void CreateBlankRecords(string, int, Applicant);

int main()
{
    string filename = "ApplicationList";

    Applicant a2;

   //a2.CreateBlankRecords();
    a2.Display();

  //a2.CreateApplication();
  //  a2.SaveApplication();

    a2.retrieveApplication(100);

    a2.Display();

    return 0;
}
