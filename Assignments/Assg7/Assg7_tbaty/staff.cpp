#include "staff.h"
#include <string>
#include <iostream>

using namespace std;

Staff::Staff()
    : Person()
{
    setSalary(0);
}

Staff::Staff(string fname, string lname, string car, int salary)
    : Person(fname, lname, car)
{
    setSalary(salary);
}

void Staff::print(std::ostream& out) const
{
    Person::print(out);
    out << " " << to_string(_salary);
}