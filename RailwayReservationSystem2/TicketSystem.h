#ifndef TICKETSYSTEM_H_INCLUDED
#define TICKETSYSTEM_H_INCLUDED

#include <iostream>
#include <vector>
#include <map>

#include "Ticket.h"

class TicketSystem
{
public:
    static std::vector<int> seats;
    static int PnrGenerator;
    static std::map<int,Ticket> bookedTicketMap;
    static std::map<int,Ticket> cancelledTicketMap;
    static std::map<int,Ticket> waitingListMap;
    static std::map<int,Ticket> partialCancelledMap;

    static int noOdWL;

    bool checkSeatAvailability(int PNR, char source, char destination, char noOfSeats); // check is seats or available or not..
    void storeInBookedMap(int PNR, char source, char destination, int noOfSeats); // will store in bookedTicketMap
    void decreaseSeatAvailability(int PNR, char source, char destination, char noOfSeats); // decrease the available seats in seats vector

    void storeInWaitingListMap(int PNR, char source, char destination, int noOfSeats); // will store in Waiting List Map
    void initiatePartilCancel(int PNR, int noOfSeats); // decrease the seat in Booked Map by PNR
    void increaseSeatAvailability(int PNR, char source, char destination, int noOfSeats); // increase seats in seats vector
    void storeInPartialCancelMap(int PNR, char source, char destination, int noOfSeat); // store in partial map
    void initiateFullCancel(int PNR, int noOfSeat);
    void waitingListActivator();
};

#endif // TICKETSYSTEM_H_INCLUDED
