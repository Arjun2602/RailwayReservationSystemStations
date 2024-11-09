#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED

#include <string>

class Ticket
{
public:
    int PNR;
    char source;
    char destination;
    int noOfSeats;
    std::string ticketStatus;

    Ticket();
    Ticket(int PNR, char source, char destination, int noOfSeats, std::string ticketStatus);
};

#endif // TICKET_H_INCLUDED
