///@author      Andrés Breucop
///@file        Calendar.h
///@version     2021-02-11
///@brief       This is the header file for the Calendar class object.

#ifndef Calendar_h
#define Calendar_h

#include "Date.h"

namespace customCal
{

    class Calendar: private Date
    {
    public:
//------------------------------------------------------------------------------
/// @brief        This is the default constructor. This function will
///                initialize the calendar to today's date.
//------------------------------------------------------------------------------
        Calendar();
//------------------------------------------------------------------------------
/// @brief        This is the paramaterized constructor. The function will
///                perform input validation for values passed. If invalid,
///                  variables are set to 0. Month and day are initalized to
///                     1 by default.
/// @param   y     Holds the year value
/// @param   m     Holds the month value
//------------------------------------------------------------------------------
        Calendar(int y, int m);
//------------------------------------------------------------------------------
/// @brief        This function will increase the calendar by 1 month.
///                If month would be greater than 12, year is incremented.
//------------------------------------------------------------------------------
        void   nextMonth();
//------------------------------------------------------------------------------
/// @brief        This function will decrease the calendar by 1 month.
///                If month would be less than 1, year is decremented.
//------------------------------------------------------------------------------
        void   prevMonth();
//------------------------------------------------------------------------------
/// @brief        This function returns a string holding a printed text calendar
///                calendar.
/// @return       string holding calendar of month
//------------------------------------------------------------------------------
        std::string to_string();
//------------------------------------------------------------------------------
/// @brief        This function calculates the first day of the week in a month
///                 for a given date.
/// @note         Algorithm for this function retrieved from:
///           https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
/// @return       a number corresponding to the day of the week (0-6: Sun-Sat)
//------------------------------------------------------------------------------
        int firstDay();
    };
}

#endif /* Calendar_h */
