#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <assert.h>
#include "employee.h"

using namespace std;

void genNewEmps(vector<Employee>& v);
int genID(vector<Employee>& v);
int getRand(int lower, int upper);
string genName();
void genDaysWorked(int *daysWorked);
void genSales(int *monthlySales, int *daysWorked, int salary);

/*
    todo
    [x] implement sortAsc
    [x] sort out getRand(lower, upper)
    [x] sort out genID()
*/
int main()
{
    //seed srand
    srand(time(NULL));
    #ifdef DEBUG
    cerr << "debug: seeded srand" << endl;
    #endif

    //declare variables
    vector<Employee> vEmp;

    //generate new employees
    genNewEmps(vEmp);

    //print to output file "data.txt"
    printAll(vEmp);

    return 0;
}

/*
    generates a list of 5000 Employee types. daysWorked[] and monthlySales[]
    are each arrays which contain monthly data.
*/
void genNewEmps(vector<Employee>& v)
{
    int empID;
    string firstname;
    string lastname;
    int storeID;
    int salary;
    int daysWorked[12];
    int monthlySales[12];

    //while vEmp.size() < 5000
    while (v.size() < 5000)
    {
        //re-/initialize arrays
        for (int i = 0; i < 12; i++)
            daysWorked[i] = monthlySales[i] = 0;

        #ifdef DEBUG
        for (int i = 0; i < 12; i++)
            cerr << "debug: daysWorked[" << i << "]: " << daysWorked[i] << endl;
        #endif

        //gather info
        empID = genID(v);
        firstname = genName();
        lastname = genName();
        storeID = getRand(1000, 9999);
        salary = getRand(20000, 100000);
        genDaysWorked(daysWorked);
        genSales(monthlySales, daysWorked, salary);

        v.push_back(Employee(empID, firstname, lastname, storeID, 
                            salary, daysWorked, monthlySales));
        #ifdef DEBUG
        cerr << "debug: added " << empID << " to list" << endl;
        #endif
    }

    #ifdef DEBUG
    cerr << "debug: v.size(): " << v.size() << endl;
    #endif

    sortAscByEmpID(v);
    #ifdef DEBUG
    cerr << "debug: sorted v in ascending order by empID" << endl;
    cerr << "debug: first ten elements of v:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cerr << "\tv[" << i << "]: " ;
        v[i].printMember(cerr);
    }

    cerr << "debug: last ten elements of v:" << endl;
    for (int i = v.size() - 10; i < v.size(); i++)
    {
        cerr << "\tv[" << i << "]: " ;
        v[i].printMember(cerr);
    }
    #endif

}

/*
    generate a unique 6-digit employee ID number in the range [100000, 999999].
    could this be a static member function of Employee, manipulating a static
    ID variable?
*/
int genID(vector<Employee>& v)
{
    bool unique = false;
    int tempID = 0;
    //while ID not unique
    while (!unique)
    {
        //generate random ID
        tempID = getRand(100000, 999999);
        #ifdef DEBUG
        cerr << "debug: checking " << tempID << endl;
        #endif
        
        //check for uniqueness
        //if list is empty, ID is unique
        if (v.size() == 0)
        {
            #ifdef DEBUG
            cerr << "debug: list empty; " << tempID << " is unique by default" << endl;
            #endif

            return tempID;
        }
        //else search for ID in list
        else
        {
            //if found, try again
            if (find(tempID, v) != -1) 
            {
                #ifdef DEBUG
                cerr << "debug: " << tempID << " found in list; trying again" << endl;
                #endif
                continue;
            }
            //else ID is unique
            else 
            {
                unique = true;
                #ifdef DEBUG
                cerr << "debug: " << tempID << " is unique" << endl;
                #endif
            }
        }
    }

    return tempID;
}

/*
    generates a (pseudo) random integer between 
    lower and upper bounds, inclusive
*/
int getRand(int lower, int upper)
{
    int result = (rand()) % (upper + 1) + lower;
    while (result < lower || result > upper)
    {
        result = (rand()) % (upper + 1) + lower;
    }

    return result;
}

//generate random first name of length [8, 16] containing chars [a-z][^*]
string genName()
{
    //generate a length between [8, 16]
    int length = getRand(8, 16);
    string result = "";
    
    //while string length < required length
    for (int i = 0; i < length; i++)
    {
        //string[n] = random char between [97, 122][^**]
        char letter = getRand(97, 122);
        result += letter;
    }
    #ifdef DEBUG
    cerr << "debug: name: " << result << endl;
    #endif

    return result;
}

//generate random number of days worked in range [0, 21]; should reflect annual amount[^*]
void genDaysWorked(int *daysWorked)
{
    // for each month
    //    daysworked = getRand(0, 21);
    for (int i = 0; i < 12; i++)
    {
        daysWorked[i] = getRand(0, 21);
    }
}

//generate monthly sales totals * 12 months[^*]
void genSales(int *monthlySales, int *daysWorked, int salary)
{
    //for each month
    for (int i = 0; i < 12; i++)
    {
        //for each day worked
        for (int j = 0; j < daysWorked[i]; j++)
        {
            if (salary < 60000) monthlySales[i] += getRand(1000, 15000);
            else monthlySales[i] += getRand(3000, 20000);
        }
        #ifdef DEBUG
        cerr << "debug: monthly sales made for month " << i << ": " << monthlySales[i] << endl;
        cerr << endl;
        #endif
    }
    #ifdef DEBUG
    cerr << endl;
    #endif
}