#include "TicketSystem.h"
//====================================================
// statics data members...
std::map<int,Ticket> TicketSystem::bookedTicketMap;
std::map<int,Ticket> TicketSystem::cancelledTicketMap;
std::map<int,Ticket> TicketSystem::waitingListMap;
std::map<int,Ticket> TicketSystem::partialCancelledMap;

std::vector<int> TicketSystem::seats(5,8);
int TicketSystem::PnrGenerator = 1;
int TicketSystem::noOdWL = 0;
//====================================================

// ************************** check the seats availability **************
bool TicketSystem::checkSeatAvailability(int PNR, char source, char destination, char noOfSeats)
{
    // [8, 8, 8, 8, 8]
    for(int i = source - 'A'; i < destination-'A'; i++)
    {
        if(seats[i] < noOfSeats)
        {
            return false;
        }
    }
    return true;
}

// *************************         storing the ticket in booked map
void TicketSystem::storeInBookedMap(int PNR, char source, char destination, int noOfSeats)
{
    bookedTicketMap[PNR] = Ticket(PNR, source, destination, noOfSeats, "Booked");
}

// *************************         decrease the available seats in seats vector
void TicketSystem::decreaseSeatAvailability(int PNR, char source, char destination, char noOfSeats)
{
    for(int i = source-'A' ; i < destination-'A'; i++)
    {
        seats[i] -= noOfSeats;
    }
}

// ****************************  storing ticket in Waiting List Map    **************
void TicketSystem::storeInWaitingListMap(int PNR, char source, char destination, int noOfSeats)
{
    waitingListMap[PNR] = Ticket(PNR, source, destination, noOfSeats, "WaitingList");
}

// **************************** increase available seats in seat vector   *************************

void TicketSystem::increaseSeatAvailability(int PNR, char source, char destination, int noOfSeats)
{
    for(int i = source - 'A'; i < destination - 'A'; i++)
    {
        seats[i] += noOfSeats;
    }
}

//  ****************************  store in partial cancel map  ****************************

void TicketSystem::storeInPartialCancelMap(int PNR, char source, char destination, int noOfSeat)
{
    std::string s = "Partial Cancel";
    TicketSystem::partialCancelledMap[PNR] = Ticket(PNR, source, destination, noOfSeat, s);
}

// waiting List activator

void TicketSystem::waitingListActivator()
{
    // book for waiting List // decrease WL seat count

    std::vector<int> toremoveFromWLMap;
    for(auto x : waitingListMap)
    {
        int PNR = x.first;
        Ticket ticket = x.second;
        if(checkSeatAvailability(ticket.PNR,ticket.source,ticket.destination, ticket.noOfSeats))
        {
            storeInBookedMap(ticket.PNR,ticket.source,ticket.destination, ticket.noOfSeats);
            decreaseSeatAvailability(ticket.PNR,ticket.source,ticket.destination, ticket.noOfSeats);
            noOdWL -= ticket.noOfSeats;
            toremoveFromWLMap.push_back(PNR);
        }
    }
    for(auto x : toremoveFromWLMap)
    {
        waitingListMap.erase(x);
    }
}

// ****************************  decrease seats in booked map for partial canceling   ****************

void TicketSystem::initiatePartilCancel(int PNR, int noOfSeat)
{

    int actualSeats = 0;
    int finalSeats = 0;
    char source = TicketSystem::bookedTicketMap[PNR].source;
    char destination = TicketSystem::bookedTicketMap[PNR].destination;

    actualSeats = TicketSystem::bookedTicketMap[PNR].noOfSeats;
    finalSeats = actualSeats - noOfSeat;

    // decrease seat in booked map using PNR
    TicketSystem::bookedTicketMap[PNR].noOfSeats = finalSeats;
    std::cout << "\nTickets from PNR - " << PNR << " will be cancelled";

    {
        // increase seat counts in seats
        increaseSeatAvailability(PNR, source, destination,noOfSeat);

    }
    {
        std::cout << "\nInitialting WL";
         waitingListActivator();
    }
    {

        // store in Partial booking
        std::cout << "\nExecuting storing in partial map";
        storeInPartialCancelMap(PNR, source, destination, noOfSeat);
    }




}

// ******************************************** initiate full cancel   ******************************
void TicketSystem::initiateFullCancel(int PNR, int noOfSeat)
{
    //1)  remove from booked map // store in cancelled map
    //  if partial ticket there in partial map ?  add them with actual ticket seat remove from partial follow 1)
    // else follow 1)

    Ticket t = bookedTicketMap[PNR];
    TicketSystem::bookedTicketMap.erase(PNR); // remove from booked map

    char source = t.source;
    char destination = t.destination;
    int noOfSeats = t.noOfSeats;
    std::cout << "\n" << noOfSeats << " from PNR: " << PNR << " Cancelled";
    increaseSeatAvailability(PNR, source, destination,noOfSeats); // will increase the seats in seat vector

    std::string s = "Cancelled";
    if(partialCancelledMap.find(PNR) != partialCancelledMap.end())
    {
        noOfSeats += partialCancelledMap[PNR].noOfSeats;
        cancelledTicketMap[PNR] = Ticket(PNR, source, destination, noOfSeats, s);
        partialCancelledMap.erase(PNR);
    }else
    {
        cancelledTicketMap[PNR] = Ticket(PNR, source, destination, noOfSeats, s);
    }
    waitingListActivator();
}
