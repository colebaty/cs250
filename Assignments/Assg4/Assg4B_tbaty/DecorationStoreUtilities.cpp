#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "DecorationStoreUtilities.h"

using namespace std;

//this function is called after adding two Money values together to ensure
//the cent amount does not exceed 99 (100 cents is one dollar).
void Money::normalize(Money& money)
{
    if (money.cents > 99)
    {
        //increment dollar amount
        money.dollars ++;
        //reduce number of pennies by 100
        money.cents -= 100;
    }
}

Money toMoney(double money)
{
    int totalPennies = money * 100;
    int dollars = totalPennies / 100;
    int pennies = totalPennies % 100;

    return Money {dollars, pennies};

}

//prints the contents of a Money struct as $DD.CC; does not
//include newline
void print(Money money)
{
    cout << "$";
    if (money.dollars < 10)
        cout << "0" << money.dollars;
    else
        cout << money.dollars;

    cout << ".";

    if (money.cents < 10)
        cout << "0" << money.cents;
    else
        cout << money.cents;
}

//returns the contents of a Money object as a double
double toDouble(Money money)
{
    return money.dollars + static_cast<double>(money.cents / 100.0);
}

//compares two `Money` types 
//returns `true` if `this` money amount is
//less than or equal to `other` money amount
bool Money::lessThan(const Money& other)
{
    return (dollars < other.dollars) 
            || ((dollars == other.dollars) && (cents <= other.cents));
}

Date toDate(string date)
{
    int month, day, year;
    char garbage;//to read over the colon in the date string

    istringstream dateIn(date);
    dateIn >> month >> garbage >> day >> garbage >> year;
    return Date {month, day, year};
}

//returns the contents of a Date struct as a
//string in the format MM:DD:YYYY
string toString(Date date)
{
    string result = "";
    if (date.month < 10)
    {
        result.append("0");
        result.append(to_string(date.month));
    }
    else
        result.append(to_string(date.month));

    result.append(":");

    if (date.day < 10)
    {
        result.append("0");
        result.append(to_string(date.day));
    }
    else
        result.append(to_string(date.day));

    result.append(":");

    result.append(to_string(date.year));

    return result;
}

//prints the contents of a Dimensions struct as
//HH:WW:DD; does not include newline
Dimensions toDimensions(string dimensions)
{
    int height, width, depth;
    char garbage;//to read over the colon in the dimensions string

    istringstream dimensionsIn(dimensions);
    dimensionsIn >> height >> garbage >> width >> garbage >> depth;

    return Dimensions {height, width, depth};

}

string toString(Dimensions dimensions)
{
    string result = "";

    result.append(to_string(dimensions.height));
    result.append(":");
    result.append(to_string(dimensions.width));
    result.append(":");
    result.append(to_string(dimensions.depth));

    return result;
}

//called after adding two dates together, this function ensures date element
//adheres to MM:DD:YYYY format; i.e. month does not exceed 12, date does not
//exceed 31. this function accounts for leap years
void Date::normalize(Date& date)
{
    switch (date.month)
    {
    //months with 31 days
    case 1://January
    case 3://March
    case 5://May
    case 7://July
    case 8://August
    case 10://October
    case 12://December
        if (date.day > 31)
        {
            if (date.month == 12)
            {
                date.year++;
                date.month = 1;
                date.day = 1;
            }
            else
            {
                date.month++;
                date.day = 1;
            }
        }
        break;

    //months with 30 days
    case 4://April
    case 6://June
    case 9://September
    case 11://November
        if (date.day > 30)
        {
            date.month++;
            date.day=1;
        }
        break;

    /*
    february and leap years:
    if the year is evenly divisible by 4, then it is a leap year, except
        -if the year is also divisible by 100, it is not a leap year, except
            -if the year is also divisible by 400, it is a leap year
    */
    case 2:
        //leap year
        if (date.year % 4 == 0)
        {
            if (date.year % 400 == 0)//leap year
            {
                if (date.day > 29)
                {
                    date.month++;
                    date.day = 1;
                }
            }
            else if (date.year % 100 == 0)//not a leap year
            {
                if (date.day > 28)
                {
                    date.month++;
                    date.day = 1;
                }
            }

        }
        break;

    default:
        break;
    }
}
