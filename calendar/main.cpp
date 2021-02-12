///@author      Andrés Breucop
///@file        main.cpp
///@version     2021-02-11
///@brief       This program tests functionality of the Calendar class object.

#include <iostream>
#include <ctime>
#include "Date.h"
#include "Calendar.h"

int main()
{
    std::cout << "Print calendar for year 2021:\n" << std::endl;
    for (int index = 1; index <= 12; index++)
    {
    customCal::Calendar cal1(2021, index);
    std::cout << cal1.to_string();
    }
    return 0;
}
