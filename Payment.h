//Payment Class 

#include <iostream>
using namespace std;


class Payment{

    private:
          int PaymentID;
          string Payment_date;
          float Payment_amount;
          int Ticket_number;

    public:
       //default constructor//
          Payment()
          {
             PaymentID = 0;
             Payment_date = "";
             Payment_amount = 0.00;
             Ticket_number = 0;
          }

          //primary constructor
          Payment (int payid, string paydate, float amount, int ticketnum)
          {
            PaymentID = payid;
            Payment_date = paydate;
            Payment_amount = amount;
            Ticket_number = ticketnum;
          }

          //copy constructor
          Payment (Payment &payment)
          {
            badgenumber = jcf.badgenumber;
            firstname = jcf.firstname;
            lastname = jcf.lastname;
            assignedStation = jcf.assignedStation;
          }
           
          //Function for calculating payment amount
          void CalculatePayment()
          {
              
          }

          //Function to view each payment
          void ViewPayment()
          {

          }
          

};

int main()
{

}
