// Main function

#include <iostream>
#include "Applicant.h"
using namespace std;

int main()
{
  Applicant a2;

  a2.CreateBlankRecords();
  a2.Display();
  a2.CreateApplication();
  a2.SaveApplication();

  a2.retrieveApplication(100);

  return 0;
}
