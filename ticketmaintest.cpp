#include <Ticket.h>

int main() {
    // Using default constructor
    Ticket defaultTicket;
    cout << "Default Ticket Report:" << endl;
    defaultTicket.viewTicketReport();

    // Using parameterized constructor
    Ticket ticket(12345, "2024-11-01", "Speeding", "SP123", "AB-1234", 150.0, "2024-11-30", "2024-12-15", "Officer Smith", "Downtown Court");
    cout << "\nInitialized Ticket Report:" << endl;
    ticket.viewTicketReport();

    return 0;
}