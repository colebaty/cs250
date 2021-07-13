#include "staff.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

void printStaffHeader(ostream& out);

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

Staff* readStaff(istream& in, int& size)
{
    // read first line for number of staff
    in >> size >> ws;
    // in >> size;

    //create dynamic array of staff with number read from first line
    Staff *list = new Staff[size];

    // read each remaining line; populate array
    char fname[50];
    char lname[50];
    char car[50];
    int salary = 0;

    string line = "";
    getline(in, line);

    int i = 0;
    while (in && i < size)
    {
        #ifdef DEBUG
            cerr << "line: " << line << endl;
        #endif

        istringstream linein(line);
        linein.get(fname, 100, ' ');
        linein >> ws;//advance linein; get does not extract delimiter
        linein.get(lname, 100, ' ');
        linein >> ws;
        linein.get(car, 100, ' ');
        linein >> ws;
        linein >> salary;

        #ifdef DEBUG
            cerr << "list[" << i << "]:" << endl
                 << "fname: " << fname << endl
                 << "lname: " << lname << endl
                 << "car: " << car << endl
                 << "salary: " << salary << endl;
        #endif
        
        list[i] = Staff(string(fname), string(lname), string(car), salary);
        #ifdef DEBUG
            cerr << "list[" << i << "]: " << list[i] << endl << endl;
        #endif
        getline(in, line);
        i++;
    }

    return list;
}

void printStaff(std::ostream& out, Staff *list, const int& size)
{
    printStaffHeader(out);
    for (int i = 0; i < size; i++)
    {
        out << left 
            << setw(20) << list[i].getFName() + " " + list[i].getLName() << "|  "
            << setw(18) << list[i].getCar() << "|  "
            << setw(18) << list[i].getSalary() << endl;
    }

    out << endl;

}

void printStaffHeader(ostream& out)
{
    out << "********************************" << endl;
    out << "********** Staff List **********" << endl;
    out << "********************************" << endl << endl;

    out << left 
        << setw(20) << "Name" << "|  " 
        << setw(18) << "Car" << "|  " 
        << setw(20) << "Salary" << endl;

    out << right << setfill('_') << setw(60) << " " << endl;
    out << setfill(' ');

};