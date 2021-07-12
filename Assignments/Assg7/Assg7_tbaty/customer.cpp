#include "customer.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Customer::Customer()
    : Person()
{
    setBalance(0.0);
    setPreferred(false);
}

Customer::Customer(string fname, string lname, string car, double balance, bool isPreferred)
    : Person(fname, lname, car)
{
    setBalance(balance);
    setPreferred(isPreferred);
}

void Customer::print(ostream& out) const
{
    cout << Person::getFName() + " " + Person::getLName() << " " 
         << isPreferred() << " " 
         << Person::getCar() << " "
         << fixed << showpoint << setprecision(2) << getBalance();
}