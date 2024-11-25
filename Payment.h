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
            PaymentID = payment.payid;
            Payment_date = payment.paydate;
            Payment_amount = payment.amount;
            Ticket_number = payment.ticketnum;
          }

          //Setters
          void setPaymentID (int payid)
          {
            PaymentID = payid;
          }

          void setPaymentDate (const string &paydate)
          {
             Payment_date = paydate;
          }
          
          void setPaymentAmount (float amount)
          {
             Payment_amount = amount;
          }

          void TicketNumber (int ticketnum)
          {
            Ticket_number = ticketnum;
          }

          //Getters
          int getPaymentID () const
          {
            return payid;
          }

          string getPaymentDate () const
          {
             return paydate;
          }

          float getPaymentAmount() const
          {
             return amount;
          }

          int getTicketNumber () const
          {
            return ticketnum;
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
