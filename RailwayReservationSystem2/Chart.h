#ifndef CHART_H_INCLUDED
#define CHART_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "TicketSystem.h"

class Chart
{
public:
    static std::vector<std::vector<char>> board;
    void prepareChart();
    void prepareBoard();
    void printChart();
};

#endif // CHART_H_INCLUDED
