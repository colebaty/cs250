#ifndef __EMPLOYEEREPORT_H__
#define __EMPLOYEEREPORT_H__

#include "employee.h"

struct EmployeeReport: public Employee
{
    static double _minimumSales;
    static double _avgCoSales;
    static double _totalCoSales;
    static double _totalCoBonuses;

    EmployeeReport();
    EmployeeReport(int empID, std::string firstname, std::string lastname, 
                   int storeID, int salary, int totalDaysWorked, int* monthlySales);
    ~EmployeeReport();

    int _totalDaysWorked;
    double _totalSales;
    double _bonus;

    /**
     * @brief calculates the Employee's bonus; must be called AFTER list is sorted,
     * as the static variable _minimumSales is populated with last member of list 
     * (i.e. the employee with the lowest totalSales). updates static variable
     * _totalCoBonuses each time it's called
     * 
     */
    void calculateBonus();

    /**
     * @brief computes and populates the value for static member _avgCoSales
     * 
     * @param v the list from which the sales information is derived
     */
    static void calcAvgSales(std::vector<EmployeeReport> v);

    /**
     * @brief prints a single member on one line IAW assignment instructions
     * 
     * @param out the outstream to print to
     */
    void printMember(std::ostream& out);
};

/**
 * @brief prints all records to output file, one per line in the specified format,
 *        sorted in descending order of employee total sales. appends 
 *        - top 10 highest sales
 *        - bottom 10 lowest sales
 *        - average company sales
 *        - total company sales 
 *        - total company bonuses
 * 
 * @param v the list of employee records
 */
void printReport(std::vector<EmployeeReport> v);

/**
 * @brief sorts the vector in descending order by totalSales
 * 
 * @param v the list to be sorted
 */
void sortDescByTotalSales(std::vector<EmployeeReport> v);

#endif //__EMPLOYEEREPORT_H__