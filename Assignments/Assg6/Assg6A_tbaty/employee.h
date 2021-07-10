#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <string>

struct Employee
{
    int _empID;
    std::string _firstname;
    std::string _lastname;
    int _storeID;
    int _salary;
    int _daysWorkedPerMonth[12];
    int _monthlySales[12];

    Employee();
    Employee(int empID, std::string firstname, std::string lastname, 
             int storeID, int salary, int* daysWorkedPerMonth, int* monthlySales);
    bool empIDgt(Employee other) {return _empID > other._empID;};//inline function
    bool empIDeq(Employee other) {return _empID == other._empID;};//inline function
    //prints member information to the given ostream
    void printMember(std::ostream& out);
    int getEmpID() {return _empID;};
};

/*
    adds an employee in ascending order of empID
*/
void addEmployee(Employee e, std::vector<Employee> v);

/*
 * sorts the given vector in ascending order by empID
 */
void sortAscByEmpID(std::vector<Employee>& v);

/*
    searches for an occurrence of empID in the given vector. returns -1 if no
    such element found; returns the index of the element if found
    [ ] implement binary search
*/
int find(int empID, std::vector<Employee>& v);

void printAll(std::vector<Employee>& v);
#endif
