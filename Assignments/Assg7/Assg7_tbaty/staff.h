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

        /**
         * @brief returns the salary of the staff
         * 
         * @return int the salary of the staff
         */
        int getSalary() const { return _salary; };
        /**
         * @brief Set the Salary object
         * 
         * @param salary 
         */
        void setSalary(int salary) { _salary = salary; };

        void print(std::ostream& out) const;
};

inline
std::ostream& operator<< (std::ostream& out, const Staff& s)
{
    s.print(out);
    return out;
}

/**
 * @brief read the given file into a dynamic Staff array
 * 
 * @param in the file containing Staff information
 * @param size the size of the array
 * @return Staff* a pointer to the dynamic Staff array
 */
Staff* readStaff(std::istream& in, int& size);

/**
 * @brief prints the Staff list in the format prescribed by the assignment 
 * instructions
 * 
 * @param out the stream to which to print
 * @param list the list containing staff information
 * @param size the size of the list
 */
void printStaff(std::ostream& out, Staff *list, const int& size);

#endif //__STAFF_H__