#ifndef __DECORATIONSTOREUTILITIES_H__
#define __DECORATIONSTOREUTILITIES_H__

#include <string>

using namespace std;

struct Money
{
    int dollars;
    int cents;
    void normalize(Money& money);
    bool lessThan(const Money& other);
};

Money toMoney(double money);
double toDouble(Money money);

struct Date
{
    int month, day, year;
    void normalize(Date& date);
};

Date toDate(string date);
string toString(Date date);

struct Dimensions
{
    int height, width, depth;
};

Dimensions toDimensions(string dimensions);
string toString(Dimensions dimensions);

#endif // __DECORATIONSTOREUTILITIES_H__
