#include "Person.h"

#include <iostream>
#include <string>

using namespace std;

Person::Person()
{
    _firstname = "";
    _lastname = "";
    _car = "";
}

Person::Person(string fname, string lname, string car)
{
    _firstname = fname;
    _lastname = lname;
    _car = car;
}
