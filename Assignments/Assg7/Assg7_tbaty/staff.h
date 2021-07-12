#ifndef __STAFF_H__
#define __STAFF_H__

#include <string>
#include "person.h"

class Staff: public Person
{
    private:
        int _salary;

    public:
        //constructors
        Staff();
        Staff(std::string fname, std::string lname, std:: string car, int salary);

        //manipulators
        int getSalary() const { return _salary; };
        void setSalary(int salary) { _salary = salary; };

        void print(std::ostream& out) const;
};

inline
std::ostream& operator<< (std::ostream& out, const Staff& s)
{
    s.print(out);
    return out;
}

#endif //__STAFF_H__