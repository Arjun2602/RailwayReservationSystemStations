#include "Chart.h"

std::vector<std::vector<char>> Chart::board(9,std::vector<char>(6,' '));
//===============================================


void Chart::printChart()
{
    std::cout << "\nAvailable seats: [ ";
    for(auto x : TicketSystem::seats)
    {
        std::cout << x << " ";
    }
    std::cout << "]" << std::endl;
    std::cout << "\nBooked Tickets: ";
    for(auto x : TicketSystem::bookedTicketMap)
    {
        Ticket t = x.second;
        std::cout << "\nPNR: " << t.PNR << " Source: " << t.source << " Destination: " << t.destination << " No of tickets: " << t.noOfSeats << " Status: " << t.ticketStatus;
    }
    std::cout << "\nCancelled Tickets: ";
    for(auto x : TicketSystem::cancelledTicketMap)
    {
        Ticket t = x.second;
        std::cout << "\nPNR: " << t.PNR << " Source: " << t.source << " Destination: " << t.destination << " No of tickets: " << t.noOfSeats << " Status: " << t.ticketStatus;
    }
    std::cout << "\nWaiting List seats: " << TicketSystem::noOdWL;
    std::cout << "\n" <<std::endl;
    int m = board.size();
    int n = board[0].size();
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cout << board[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
void Chart::prepareBoard()
{
    int m = board.size();
    int n = board[0].size();
    char c = 'A';
    char num = '1';
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j > 0)
            {
                board[i][j] = c + j-1;
            }else if(j == 0 && i > 0)
            {
                board[i][j] = num++;
            }else
            {
                board[i][j] = ' ';
            }
        }
    }
}

void Chart::prepareChart()
{
    //[A, B, C, D, E]
    //[0, 0, 2, 2, 8]  n
    prepareBoard();
    //int m = board.size(); // 9
    int n = board[0].size(); // 6

    for(int j = 1; j < n; j++)
    {
        int bookedSeat = 8 - TicketSystem::seats[j-1];
        for(int i = 1; i <= bookedSeat; i++)
        {
            board[i][j] = '*';
        }
    }

    printChart();
}
