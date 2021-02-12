///@author      Andrés Breucop
///@file        Date.cpp
///@version     2021-02-11
///@brief       This is the implementation file for the Date class object.

#include "Date.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

const int BASE_YEAR = 1900;                 //lowest year allowed
const int MAX_MONTHS = 12;                  //months in a year


//------------------------------------------------------------------------------
//                       C O N S T R U C T O R S
//------------------------------------------------------------------------------


Date::Date (int y, int m, int d)
{
    if (isValid (y, m , d) == true)
    {
        setDate (y, m, d);
    }
    else
    {
        setDate(0, 0, 0);
        cerr << "Values specified are not valid. Date set to 0/0/0." << endl;
    }
}

Date::Date ()
{
    time_t totalTime;           //variable to hold current time in seconds
    tm timeSpecs;

    if (time(&totalTime) == -1)
    {
        cerr << "Class construction failed." << '\n' <<
        "Unable to get system time." << endl;
    }
    else
    {
        time(&totalTime);

        timeSpecs = *localtime(&totalTime);

        year = timeSpecs.tm_year + BASE_YEAR;
        month = timeSpecs.tm_mon + 1;
        day = timeSpecs.tm_mday;
    }
}

void Date::addDays (int n)
{
    tm timeSpecs;               //initialized tm struct
    timeSpecs.tm_year = year - BASE_YEAR;
    timeSpecs.tm_mon = month - 1;
    timeSpecs.tm_mday = day + n;

    mktime(&timeSpecs);

    year = timeSpecs.tm_year + BASE_YEAR;
    month = timeSpecs.tm_mon + 1;
    day = timeSpecs.tm_mday;
}

//------------------------------------------------------------------------------
//                            G E T T E R S
//------------------------------------------------------------------------------


int Date::dayOfWeek() const
{
    time_t totalTime;           //variable to hold seconds since epoch
    tm timeSpecs;

    if (time(&totalTime) == -1)
    {
        cerr << "Unable to get system time." << endl;
    }
    else
    {
        time(&totalTime);

        timeSpecs = *localtime(&totalTime);
    }

    return timeSpecs.tm_wday;
}

int Date::dayOfYear () const
{
    time_t totalTime;           //variable to hold seconds since epoch
    tm timeSpecs;

    if (time(&totalTime) == -1)
    {
        cerr << "Unable to get system time." << endl;
    }
    else
    {
        time(&totalTime);

        timeSpecs = *localtime(&totalTime);
    }

    return timeSpecs.tm_yday + 1;
}

int Date::daysInMonth (int y, int m)
{
    const int MONTH_DAYS[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30,
    31, 30, 31};                            //array holding days in a month

    int days;                           //return variable

    if (m == 2 && isLeapYear(y) == false)
    {
        days = MONTH_DAYS[m] - 1;
    }
    else
    {
        days = MONTH_DAYS[m];
    }

    return days;
}

int Date::daysRemaining () const
{
    int daysRem;                    //return variable
    time_t totalTime;           //variable to hold seconds since epoch
    tm timeSpecs;

    if (time(&totalTime) == -1)
    {
        cerr << "Unable to get system time." << endl;
    }
    else
    {
        time(&totalTime);

        timeSpecs = *localtime(&totalTime);
    }

    daysRem = 365 - (timeSpecs.tm_yday + 1);

    return daysRem;
}

bool Date::isLeapYear (int y)
{
    bool state = false;            //boolean variable to determine leap year

    if (y % 4 != 0)
    {
        state = false;
    }
    else if (y % 100 != 0)
    {
        state = true;
    }
    else if (y % 400 != 0)
    {
        state = false;
    }
    else
    {
        state = true;
    }

    return state;
}

//------------------------------------------------------------------------------
//                            S E T T E R S
//------------------------------------------------------------------------------

void Date::setDay (int d)
{
    if (d < 1 || d > daysInMonth(year, month))
    {
        cerr << "Unable to set day. Value is out of range." << endl;
    }
    else
    {
        day = d;
    }
}

void Date::setMonth (int m)
{
    if (day > daysInMonth(year, m))
    {
        cerr << "Unable to set month. This date does not exist for the month"
        << endl;
    }
    else if (m < 1 || m > MAX_MONTHS)
    {
        cerr << "Unable to set month. Months must be in the range of 1-12."
        << endl;
    }
    else
    {
        month = m;
    }
}

void Date::setYear (int y)
{
    if (y < BASE_YEAR)
    {
        cerr <<
        "Unable to set year. Year must be greater than 1900."
        << endl;
    }
    else
    {
        year = y;
    }
}


void Date::setDate(int y, int m, int d )
{
    if (isValid (y, m , d) == true)
    {
        year = y;
        month = m;
        day = d;
    }
    else
    {
        cerr << "The values are not valid." << endl;
    }
}

//------------------------------------------------------------------------------
//                            O T H E R S
//------------------------------------------------------------------------------

bool Date::isValid(int y, int m, int d)
{
    bool state = false;          //holds return variable

    if (y >= BASE_YEAR && m >= 1 && d >= 1)
    {
        if (d >! daysInMonth(y, m))
        {
            state = true;
        }
    }
    else
    {
        cerr << "Invalid date components." << endl;
    }

    return state;
}

string Date::to_string ()
{
    string date = ::to_string(year) + '/' + ::to_string(month) + '/' +
    ::to_string(day);

    return date;
}
