#include "Canceller.h"

void Canceller::initiateCancel()
{
    int PNR = 0;
    int noOfSeats = 0;

    std::cout << "\nPNR: ";
    std::cin >> PNR;
    if(TicketSystem::bookedTicketMap.find(PNR) == TicketSystem::bookedTicketMap.end())
    {
        std::cout << "\nInvalid PNR!!";
        return;
    }
    std::cout << "No of seats: ";
    std::cin >> noOfSeats;
    TicketSystem t;
    if(noOfSeats < TicketSystem::bookedTicketMap[PNR].noOfSeats)
    {
        // partial cancel
        t.initiatePartilCancel(PNR, noOfSeats);

    }else
    {
        // full cancel
        t.initiateFullCancel(PNR,noOfSeats);
    }
}
