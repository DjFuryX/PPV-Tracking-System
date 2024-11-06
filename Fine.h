//Fine Class 

class Fine{
    private:
       string offenceCode;
        string offenceDescription;
        float fineAmount;
    
    public:
        // Default Constructor 
        Fine(){
            offenceCode = ""; 
            offenceDescription = "notSet"; 
            fineAmount = 0.0;
        }

        Fine(string Ocode, string description, float fAmount){
            offenceCode = Ocode;
            offenceDescription = description;
            fineAmount = fAmount;
        }

        // Getter Methods

        string getTicketOffenceCode(){
            return offenceCode;
        }
        float getTicketOffenceCode(){
            return offenceCode;
        }
        string getTicketOffenceDescription(){
            return ticketOffenceDescription;
        }


        //Setter methods for Fine

        void setTicketOffenceDescription(string description){
            offenceDescription = description;
        }
        void setFineAmount(float amount){
            fineAmount = amount;
        }


        // Method to link Fine to a Ticket
        void linkToTicket(const Ticket &ticket) {
            offenceCode = ticket.getTicketOffenceCode();         //Get  offence code, description and fine from Ticket
            offenceDescription = ticket.getTicketOffenceDescription(); 
            fineAmount = ticket.getTicketAmount();                    
        }

        //Generate Fine Details
        void displayFine()  {
        cout << "Ticket Offence Code: " << offenceCode << endl;
        cout << "Ticket Offence Description: " << offenceDescription << endl;
        cout << "Ticket Fine Amount: $" << fineAmount << endl;
    }
};
#endif


/*Link to Ticket Method
it created a linkage between fine and ticket 
such copying or getting the offense code and description and
fine amount from the ticket object to fine object


so it pretty much allows the fine to accurately reflect violation details
from the ticket useful when fine is issued directly based on a ticket offense */


/*Main to Test
    #include <iostream>
    #include <string.h>
    sing namespace std;

    #include <Ticket.h>
    #include <Fine.h>

    int main() {
    // Creating a Ticket instance
    Ticket ticket(12345, "2024-11-01", "1001", "Speeding", "AB-1234", 15000.0, 
                  "2024-11-30", "2024-12-15", "Officer Smith", "Spanish Town Court");

    // Fine instance that link it to the Ticket
    Fine fine;
    fine.linkToTicket(ticket);

    // Displaying ticket and fine information
    cout << "Ticket Report:" << endl;
    ticket.viewTicketReport();
    cout << "\nFine Details:" << endl;
    fine.displayFine();

    return 0;
}*/