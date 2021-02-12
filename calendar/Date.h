///@author      Andrés Breucop
///@file        Date.h
///@version     2021-02-11
///@brief       Header file for the Date class object.

#ifndef Date_h
#define Date_h

#include <string>
#include <ctime>

class Date
{
private:

    int year;               //stores year value
    int month;              //stores month value
    int day;                //stores day value

    //--------------------------------------------------------------------------
    /// @brief         Verifies that values passed are valid date components.
    /// @param   y     Holds the year value
    /// @param   m     Holds the month value
    /// @param   d     Holds the day value
    /// @return        returns 1 if successful, 0 if errors found
    //--------------------------------------------------------------------------
    bool isValid (int y, int m, int d);

public:
    //--------------------------------------------------------------------------
    /// @brief        This is the paramaterized constructor. The function will
    ///                check to make sure the date is valid. If not valid,
    ///                 member variables are initialized to 0.
    ///
    /// @param   y     Holds the year value
    /// @param   m     Holds the month value
    /// @param   d     Holds the day value
    //--------------------------------------------------------------------------
    Date(int y, int m, int d);

    //--------------------------------------------------------------------------
    /// @brief        This is the default constructor. This function will
    ///                initialize member variables to today's date.
    //--------------------------------------------------------------------------
    Date();

    //--------------------------------------------------------------------------
    /// @brief         This function adds n days to the current date stored in
    ///                 member variables, and creates a new day.
    /// @param   n     number of days to add
    /// @note          Function does not operate properly.
    //--------------------------------------------------------------------------
    void addDays (int n);

    //--------------------------------------------------------------------------
    /// @brief        This function returns the day of the week starting with
    ///                 Sunday = 0 to Saturday = 6.
    /// @return       returns integer representing day of week number
    //--------------------------------------------------------------------------
    int dayOfWeek() const;

    //--------------------------------------------------------------------------
    /// @brief        This function returns the day in the year.
    /// @return       returns integer representing day of the year
    //--------------------------------------------------------------------------
    int dayOfYear() const;

    //--------------------------------------------------------------------------
    /// @brief         This function calculates the number of days in a month,
    ///                 given a year and month.
    /// @param   y     Holds the year value
    /// @param   m     Holds the month value
    /// @return        returns integer representing days in the month specified
    //--------------------------------------------------------------------------
    static int daysInMonth (int y, int m);


    //--------------------------------------------------------------------------
    /// @brief        This function returns the number of days left in the year.
    /// @return       returns integer representing days left in year
    //--------------------------------------------------------------------------
    int daysRemaining() const;

    //--------------------------------------------------------------------------
    /// @brief        This function gets the day
    /// @return       returns integer stored in day member variable
    //--------------------------------------------------------------------------
    int getDay() const {return day;};

    //--------------------------------------------------------------------------
    /// @brief        This function gets the month
    /// @return       returns integer stored in month member variable
    //--------------------------------------------------------------------------
    int getMonth() const {return month;};

    //--------------------------------------------------------------------------
    /// @brief        This function gets the year
    /// @return       returns integer stored in year member variable
    //--------------------------------------------------------------------------
    int getYear() const {return year;};

    //--------------------------------------------------------------------------
    /// @brief        This determines if the year passed to the function is a
    ///                 leap year.
    /// @param y      Holds year value
    /// @return       returns true if leap year, false if it is a common year
    //--------------------------------------------------------------------------
    static bool isLeapYear (int y);

    //--------------------------------------------------------------------------
    /// @brief         If date is valid, this function sets member variables
    ///                to values passed.
    /// @param   y     Holds the year value
    /// @param   m     Holds the month value
    /// @param   d     Holds the day value
    //--------------------------------------------------------------------------
    void setDate (int y, int m, int d);

    //--------------------------------------------------------------------------
    /// @brief        This function will set the day to value passed by d, if it
    ///                is valid for the month and year.
    /// @param   d     Holds the day value
    //--------------------------------------------------------------------------
    void setDay (int d);

    //--------------------------------------------------------------------------
    /// @brief         This function will set the month to value passed by m, if
    ///                it is valid for the day and year.
    /// @param   m     Holds the month value
    //--------------------------------------------------------------------------
    void setMonth (int m);

    //--------------------------------------------------------------------------
    /// @brief         This function will set the year to value passed by y, if
    ///                it is valid for the month and day.
    /// @param   y     Holds the year value
    //--------------------------------------------------------------------------
    void setYear (int y);


    //--------------------------------------------------------------------------
    /// @brief        This function returns the a string containing the date
    ///                 in ISO 8601 format.
    /// @return       returns a string with date stored in member variables
    //--------------------------------------------------------------------------
    std::string to_string ();

    //--------------------------------------------------------------------------
    /// @brief        This function initializes timeSpecs variable with the
    ///                system clock's time components.
    //--------------------------------------------------------------------------
    void dateNow ();
};



#endif /* Date_h */
