#include "Ticket.h"


Ticket::Ticket()
:PNR(0),source(' '),destination(' '),noOfSeats(0),ticketStatus("")
{}

Ticket::Ticket(int PNR, char source, char destination, int noOfSeats, std::string ticketStatus)
    {
        this->PNR = PNR;
        this->source = source;
        this->destination = destination;
        this->noOfSeats = noOfSeats;
        this->ticketStatus = ticketStatus;
    }


