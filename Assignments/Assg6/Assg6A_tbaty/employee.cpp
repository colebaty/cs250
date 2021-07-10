#include <iostream>
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

    //initialize arrays
    for (int i = 0; i < 12; i++)
        _daysWorkedPerMonth[i] = _monthlySales[i] = 0;
}

Employee::Employee(int empID, string firstname, string lastname,
            int storeID, int salary, int* daysWorkedPerMonth, int* monthlySales)
{
    _empID = empID;
    _firstname = firstname;
    _lastname = lastname;
    _storeID = storeID;
    _salary = salary;

    for (int i = 0; i < 12; i++)
    {
        _daysWorkedPerMonth[i] = daysWorkedPerMonth[i];
        _monthlySales[i] = monthlySales[i];
    }
    
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

/*
    todo
    [ ] convert to insertion sort
*/
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
    // for (int firstOutOfOrder = 1; firstOutOfOrder < v.size(); firstOutOfOrder++)
    // {
    //     int value = v[firstOutOfOrder].getEmpID();
    //     int toBeMoved = firstOutOfOrder - 1;
    //     //[ ] change to member function comparision
    //     while (toBeMoved >= 0 && value < v[toBeMoved].getEmpID())
    //     {
    //         v[toBeMoved + 1] = v[toBeMoved];
    //         toBeMoved--;
    //     }

    //     v[toBeMoved - 1] = v[firstOutOfOrder];
    // }
}

void Employee::printMember(ostream& out)
{
    int totalAnnualDaysWorked = 0;
    for (int i = 0; i < 12; i++) 
        totalAnnualDaysWorked += _daysWorkedPerMonth[i];

    out << _empID << ", " << _firstname << ", " << _lastname << ", " 
        << _storeID << ", " << _salary << ", " << totalAnnualDaysWorked << ", ";
    
    for (int i = 0; i < 12; i++)
        out << _monthlySales[i] << " ";
    
    out << endl;
}

void printAll(vector<Employee>& v)
{
    ofstream outFile("data.txt");
    if (!outFile)
    {
        cerr << "Error: unable to create/open output file" << endl;
        return;
    }
    //for each employee in list
        //write employee data to "data.txt" using member print function
    for (Employee e : v)
    {
        e.printMember(outFile);
    }
    outFile.close();
}
