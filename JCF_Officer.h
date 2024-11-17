//JCF_Officer Class 

class JCF_Officer{

private:
           int badgenumber;
           string firstname;
           string lastname;
           string assignedStation;

    public: 
          
          //default constructor//
          JCF_Officer()
          {
             badgenumber = 0;
             firstname = "";
             lastname = "";
             assignedStation = "";
          }

          //primary constructor
          JCF_Officer (int bnum, string fn, string ln, string station)
          {
            badgenumber = bnum;
            firstname = fn;
            lastname = ln;
            station = assignedStation;
          }

          //copy constructor
          JCF_Officer (JCF_Officer &officer)
          {
            badgenumber = officer.badgenumber;
            firstname = officer.firstname;
            lastname = officer.lastname;
            assignedStation = officer.assignedStation;
          }
          
          //Function for adding new ticket
          void AddTicket()
          {

          }
          //Function to display the tickets that are due
          void ViewTicketsDue()
          {

          }
          //Function to view tickets
          void ViewTickets()
          {

          }
          //Function to view outstanding tickets from driver in each parish
          void TicketsParish()
          {

          }
          //Function to update ticket
          void updateTicket()
          {

          }
           //Function to view Warrant details of each driver
          void CheckWarrantStatus()
          {

          }

};

int main()
{
  
}
