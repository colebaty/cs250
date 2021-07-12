#ifndef __DECORATIONSTOREUTILITIES_H__
#define __DECORATIONSTOREUTILITIES_H__

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

Date toDate(std::string date);
std::string toString(Date date);

struct Dimensions
{
    int height, width, depth;
};

Dimensions toDimensions(std::string dimensions);
std::string toString(Dimensions dimensions);

/* 
    takes the place of former member function `sortAscByCost(<struct> *list, int count)'
    which appeared in each module
    proud of this one.

    templates are really cool.  it's abstraction of overloading. it'll be fun
    to explore this more
 */
template <typename T>
void sortAscByCost(std::vector<T>& v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i+1; j < v.size(); j++)
        {
            if (v[j].price.lessThan(v[i].price))
            {
                T temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

#endif // __DECORATIONSTOREUTILITIES_H__
