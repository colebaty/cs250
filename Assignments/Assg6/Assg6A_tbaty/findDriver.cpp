#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include "employee.h"

using namespace std;

/*
    29JUN21
    testing binary search in Employee model.  
    sorting vector by empID is not yet functional, so test data must be
    ordered by hand.
*/
int main()
{
    vector<Employee> v;

    string firstname = "blah";
    string lastname = "blahhh";

    int storeID = 1928;
    int salary = 92873989;
    int daysWorked = 999;
    string monthlySales = "98172987 91827 9817 298 71987 29871";

    //manually ordered test data
    v.push_back(Employee(0, firstname, lastname, storeID, salary, daysWorked, monthlySales));
    v.push_back(Employee(1, firstname, lastname, storeID, salary, daysWorked, monthlySales));
    v.push_back(Employee(10, firstname, lastname, storeID, salary, daysWorked, monthlySales));
    v.push_back(Employee(18, firstname, lastname, storeID, salary, daysWorked, monthlySales));
    v.push_back(Employee(19, firstname, lastname, storeID, salary, daysWorked, monthlySales));
    v.push_back(Employee(73, firstname, lastname, storeID, salary, daysWorked, monthlySales));
    v.push_back(Employee(100, firstname, lastname, storeID, salary, daysWorked, monthlySales));
    v.push_back(Employee(113, firstname, lastname, storeID, salary, daysWorked, monthlySales));
    v.push_back(Employee(1826, firstname, lastname, storeID, salary, daysWorked, monthlySales));
    v.push_back(Employee(1985, firstname, lastname, storeID, salary, daysWorked, monthlySales));

    cout << "searching for empID=0:::" << find(0, v) << endl;
    cout << "searching for empID=1:::" << find(1, v) << endl;
    cout << "searching for empID=1985:::" << find(1985, v) << endl;

    //search for an empID not in the array
    assert(find(2021, v) == -1);

    //ensure someting in the array exists
    assert(find(100, v) != -1);

    return 0;
}
