#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__

#include <string>
#include <vector>

/*
    adapted from PartA
*/
struct Employee
{
    int _empID;
    std::string _firstname;
    std::string _lastname;
    int _storeID;
    double _salary;
    int _totalDaysWorked;
    double _totalSales;
    double _bonus;

    Employee();
    Employee(int empID, std::string firstname, std::string lastname, 
             int storeID, double salary, int totalDaysWorked, double totalSales);
    bool empIDgt(Employee other) {return _empID > other._empID;};//inline function
    bool empIDeq(Employee other) {return _empID == other._empID;};//inline function
    /**
     * @brief calculates the Employee's bonus based on the formula
     * `(0.001 * salary) * (0.001 * (totalSales - minCoSales))`
     * 
     * @param minCoSales the smallest value of `totalSales` across the entire company
     */
    void calculateBonus(double minCoSales);
    void setBonus(double bonus);
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

/**
 * @brief sorts the vector in descending order by totalSales
 * 
 * @param v the list to be sorted
 */
void sortDescByTotalSales(std::vector<Employee>& v);

void printAll(std::vector<Employee>& v);
#endif
