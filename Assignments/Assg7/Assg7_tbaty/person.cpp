#include "person.h"

#include <iostream>
#include <string>

using namespace std;

Person::Person()
{
    setFName("");
    setLName("");
    setCar("");
}

Person::Person(string fname, string lname, string car)
{
    setFName(fname);
    setLName(lname);
    setCar(car);
}

void Person::print(std::ostream& out) const
{
    out << _firstname + " " + _lastname << " " << _car;
}