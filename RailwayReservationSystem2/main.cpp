#include <iostream>

#include "Booker.h"
#include "TicketSystem.h"
#include "Chart.h"
#include "Canceller.h"

using namespace std;
void module()
{
    cout << "\n\n1.Book";
    cout << "\n2.Cancel";
    cout << "\n3.print Chart";
    cout << "\n4.Exit\n";
}
int main()
{
    cout << "\t\tRailway Reservation System!!";
    bool flag = true;
    int option = 0;
    while(flag)
    {
        module();
        cin >> option;
        switch(option)
        {
        case 1:
            {
                // book
                Booker b;
                b.initiateBooking();
                break;
            }
        case 2:
            {
                // cancel
                Canceller c;
                c.initiateCancel();
                break;
            }
        case 3:
            {
                // print chart
                Chart c;
                c.prepareChart();
                break;
            }
        case 4:
            {
                // exit
                flag = false;
                break;
            }
        default:
            {
                cout << "\nInvalid Try!!";
                break;
            }
        }
    }
}
