#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "employeereport.h"

using namespace std;

double EmployeeReport::_minimumSales = 0;
double EmployeeReport::_avgCoSales = 0;
double EmployeeReport::_totalCoSales = 0;
double EmployeeReport::_totalCoBonuses = 0;

EmployeeReport::EmployeeReport()
    : Employee()
{
    _bonus = 0.0;
    _totalSales = 0.0;
}

EmployeeReport::EmployeeReport(int empID, std::string firstname, std::string lastname, 
                int storeID, int salary, int daysWorkedPerMonth, int* monthlySales)
    : Employee(empID, firstname, lastname, storeID, salary, monthlySales)
{
    _bonus = 0.0;


    //update total company sales each time a new EmployeeReport instance is created
    _totalCoSales += _totalSales;
    *_daysWorkedPerMonth = daysWorkedPerMonth;
}

EmployeeReport::~EmployeeReport()
{
    delete _daysWorkedPerMonth;
}

void EmployeeReport::calculateBonus()
{
    _bonus = (0.001 * _salary) * (0.001 * (_totalSales - _minimumSales));
    //update 
    _totalCoBonuses += _bonus;
}

void EmployeeReport::calcAvgSales(vector<EmployeeReport> v)
{
    double sumSales = 0.0;

    for (EmployeeReport e : v)
        sumSales += e._totalSales;

    _avgCoSales = sumSales / v.size();
}

void EmployeeReport::printMember(ostream& out)
{
    int totalAnnualDaysWorked = 0;
    for (int i = 0; i < 12; i++) 
        totalAnnualDaysWorked += _daysWorkedPerMonth[i];

    out << fixed << setprecision(2) 
        << _empID << ", " << _firstname << ", " 
        << _lastname << ", " << _storeID << ", " << _salary << ", " 
        << totalAnnualDaysWorked << ", " << _totalSales << ", " << _bonus;
    
    out << endl;
}

void printReport(vector<EmployeeReport>& v)
{
    ofstream outFile("results.txt");
    if (!outFile)
    {
        cerr << "Error: unable to create/open output file" << endl;
        return;
    }
    //for each employee in list
        //write employee data to "results.txt" using member print function
    outFile << fixed << setprecision(2);

    for (EmployeeReport e : v)
    {
        e.printMember(outFile);
    }

    outFile << "Top Ten Highest Sales\tempID\ttotalSales" << endl;

    for (int i = 0; i < 10; i++)
        outFile << "\t\t\t\t\t\t\t\t" << v[i]._empID << "\t" << v[i]._totalSales << endl;

    outFile << "Bottom Ten Lowest Sales\tempID\ttotalSales" << endl;

    //print in ascending order of lowest sales
    for (int i = v.size() - 1; i > v.size() - 10; i--)
        outFile << "\t\t\t\t\t\t\t\t" << v[i]._empID << "\t" << v[i]._totalSales << endl;

    outFile << "Avg Sales Across the Company: " << EmployeeReport::_avgCoSales << endl
            << "Total Sales Overall: " << EmployeeReport::_totalCoSales << endl
            << "Total Bonuses Overall: " << EmployeeReport::_totalCoBonuses << endl;

    outFile.close();
}

void sortDescByTotalSales(std::vector<EmployeeReport> v)
{
    //sort list - insertion sort?
    // [ ] investigate assignment/swap for vectors
    //      v[0] ?= v[1]
    // [ ] use member comparison function

    for (int i = 1; i < v.size(); i++)
    {
        int j = i;
        while (j > 0 && v[j-1]._totalSales < v[j]._totalSales)
        {
            EmployeeReport temp = v[j];
            v[j-1] = v[j];
            v[j] = temp;
            j--;
        }
    }

    //assign lowest/last totalSales value to _minimumSales
    EmployeeReport::_minimumSales = v.back()._totalSales;
}