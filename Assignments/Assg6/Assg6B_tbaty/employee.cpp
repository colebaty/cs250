#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

#include "employee.h"
using namespace std;

Employee::Employee()
{
    _empID = 0;
    _firstname = "";
    _lastname = "";
    _storeID = 0;
    _salary = 0;
    _totalDaysWorked = 0;
    _totalSales = 0.0;
    _bonus = 0.0;
}

Employee::Employee(int empID, string firstname, string lastname,
            int storeID, double salary, int totalDaysWorked, double totalSales)
{
    _empID = empID;
    _firstname = firstname;
    _lastname = lastname;
    _storeID = storeID;
    _salary = salary;
    _totalDaysWorked = totalDaysWorked;
    _totalSales = totalSales;
    _bonus = 0.0;
}

int find(int empID, vector<Employee>& v)
{
    int first = 0;
    int last = v.size() - 1;
    int mid = 0;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;
        if (v[mid]._empID == empID)
        {
            found = true;
        }
        else if (v[mid]._empID > empID)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found)
        return mid;
    else
        return -1;
}

void sortAscByEmpID(vector<Employee>& v)
{
    Employee temp;
    //brute force for now - change later if time
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i].empIDgt(v[j]))//member function "greater than" call
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

void sortDescByTotalSales(std::vector<Employee>& v)
{
    Employee temp;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        if (v[i]._totalSales < v[j]._totalSales)
        {
            temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
}

void Employee::calculateBonus(double minCoSales)
{
    _bonus = (0.001 * _salary) * (0.001 * (_totalSales - minCoSales));
}

void Employee::setBonus(double bonus)
{
    _bonus = bonus;
}

void Employee::printMember(ostream& out)
{

    out << fixed << setprecision(2) 
        << _empID << ", " << _firstname << ", " << _lastname << ", " 
        << _storeID << ", " << _salary << ", " << _totalDaysWorked << ", "
        << _totalSales << ", " << _bonus << endl;
}

void printAll(vector<Employee>& v)
{
    ofstream outFile("results.txt");
    if (!outFile)
    {
        cerr << "Error: unable to create/open output file" << endl;
        return;
    }
    //for each employee in list
        //write employee data to "results.txt" using member print function
    for (Employee e : v)
    {
        e.printMember(outFile);
    }
    outFile.close();
}
