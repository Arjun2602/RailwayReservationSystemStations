#include "Booker.h"


void Booker::initiateBooking()
{
    int PNR = TicketSystem::PnrGenerator;
    char source = ' ';
    char destination = ' ';
    int noOfSeats = 0;
    int num = 0;
    std::cout << "\nSource(A-E): ";
    std::cin >> source;
    if(source < 'A' || source > 'E')
    {
        std::cout << "\nInvalid Source!!";
        return;
    }
    std::cout << "Destination(A-E): ";
    std::cin >> destination;
    if(destination < 'A' || destination > 'E')
    {
        std::cout << "Invalid Destination!!";
        return;
    }
    std::cout << "No of Seats: ";
    std::cin >> noOfSeats;
    TicketSystem t;
    if(t.checkSeatAvailability(PNR, source, destination, noOfSeats))
    {
        // available ticket. need to store in booked map and decrease seats
        t.storeInBookedMap(PNR, source, destination, noOfSeats);
        t.decreaseSeatAvailability(PNR, source, destination, noOfSeats);
        std::cout << "PNR " << PNR << " booked";

    }else
    {
        // not available ticket. check and store in waiting list
        if(TicketSystem::noOdWL + noOfSeats > 2)
        {
            // no tickets available for WL
            std::cout << "\nNo Tickets Available!!";
            return;

        }else
        {
            // store in WL map and increase the seats in noOdWL
            t.storeInWaitingListMap(PNR, source, destination, noOfSeats);
            num = noOfSeats + TicketSystem::noOdWL;
            TicketSystem::noOdWL = num;
            std::cout << "\nPNR " << PNR << " booked with " << noOfSeats << " WL tickets";
        }
    }
TicketSystem::PnrGenerator++;
}
