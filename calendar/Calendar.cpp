///@author      Andrés Breucop
///@file        Calendar.cpp
///@version     2021-02-11
///@brief       This is the implementation file for the Calendar class object.

#include "Calendar.h"
#include "Date.h"
#include <ctime>
#include <string>
#include <iostream>

customCal::Calendar::Calendar() : Date() {}

customCal::Calendar::Calendar(int y, int m)
{
    setMonth(1);
    setYear(y);
    setMonth(m);
    setDay(1);

    if (Calendar::getYear() == 0 || Calendar::getMonth() == 0 ||
        Calendar::getDay() == 0)
    {
        Calendar();

        std::cerr << "Unable to set Calendar to specified date." << '\n' <<
        "Calendar is set to current month and year." << std::endl;
    }
}

void customCal::Calendar::nextMonth()
{
    if (getMonth() == 12)
    {
        setYear(getYear() + 1);
        setMonth(1);
    }
    else
    {
        setMonth(getMonth() + 1);
    }
}

void customCal::Calendar::prevMonth()
{
    if (getMonth() == 1)
    {
        setYear(getYear() - 1);
        setMonth(12);
    }
    else
    {
        setMonth(getMonth() - 1);
    }
}

std::string customCal::Calendar::to_string()
{
    const std::string months[13] = { "Blank", "January", "February", "March",
    "April", "May", "June", "July", "August", "September", "October",
    "November", "December" };                 //array holding names of the month

    const std::string weekdays[7] = { "Sun", "Mon", "Tues", "Wed",
        "Thu", "Fri", "Sat"};       //array holding days of the week

    const int spaces[7] = {3, 7, 11, 15, 19, 23, 27};     //used for spacing

    int counter = firstDay();       //keeps track of day of week

    char blanks = ' ';              //variable used for spacing

    std::string lineOne;            //1st line of output: stores month and year
    std::string lineTwo;            //2nd line of output: stores days of week
    std::string lineThree;          //3rd line of output: stores days in month
    std::string year = std::to_string(getYear()); //stores printable year number

    std::string print;              //used as return variable

   lineOne = lineOne.append(7, blanks);

   lineOne = lineOne.append(months[getMonth()]) + ' ' + year + '\n';

   for (int index = 0; index < 7; index++)
    {
        lineTwo = lineTwo + blanks + weekdays[index];
    }

    lineThree = '\n' + lineThree.append(spaces[firstDay()], blanks);

    for (int index = 1; index <= Calendar::daysInMonth(getYear(),
                                                       getMonth()); index++)
    {
        while (index < 10)
        {
            lineThree.append(std::to_string(index) + blanks);
            index++;
            counter++;
            lineThree.append(2, blanks);

            if (counter == 7)
            {
                lineThree.append(1, '\n');
                lineThree.append(3, blanks);
                counter = 0;
            }
        }

        lineThree.append(std::to_string(index));
        counter++;
        lineThree.append(2, blanks);

        if (counter == 7)
        {
            lineThree.append(1, '\n');
            lineThree.append(3, blanks);
            counter = 0;
        }
    }

    print = lineOne + lineTwo + lineThree + '\n' + '\n' ;

    return print;
}

int customCal::Calendar::firstDay()
{
    int year = (getYear() - (14-getMonth())/12);     //year used for calculation
    int month = (getMonth() + 12 * ((14-getMonth())/12) - 2);//month calculation
    int day = getDay();                               //day used for calculation

    int firstDay = ((day + year + year / 4 - year / 100
                    + year / 400 + (31 * month) / 12) % 7);    //return variable

    return firstDay;
}
