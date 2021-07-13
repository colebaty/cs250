#include <iostream>
#include <fstream>
#include <sstream>

#include "staff.h"
#include "customer.h"

using namespace std;

void printHeader(ostream& out);

int main()
{
    //print rental records for ODU rentals
    //open, read input files
    ifstream staffIn("staff.txt");
    ifstream customersIn("customers.txt");
    if (!staffIn || !customersIn)
    {
        cerr << "Error: required files not found.  Please ensure files " 
             << "\'staff.txt\' and '\'customers.txt\' "
             << "are in the current working directory" << endl;
    }

    //declare, initialize pertinent list information
    Staff *staffList = nullptr;
    Customer *custList;

    int noStaff, noCust;
    noStaff = noCust = 0;

    //read staff.txt
    #ifdef DEBUG
        cerr << "======== populating staffList ======== " << endl;
    #endif
    staffList = readStaff(staffIn, noStaff);
    //close input files
    staffIn.close();

    //read customers.txt
    #ifdef DEBUG
        cerr << "======== populating custList ======== " << endl;
    #endif
    custList = readCustomers(customersIn, noCust);
    //close input files
    customersIn.close();

    #ifdef DEBUG
        cerr << "staffList[0]: " << staffList[0] << endl;
        cerr << "custList[0]: " << custList[0] << endl;
    #endif

    //print data
    //print program header
    printHeader(cout);
    printStaff(cout, staffList, noStaff);
    printCustomers(cout, custList, noCust);
    //print staff header
        //print staff data
    //print customer header
        //print customer data
    delete [] staffList;
    delete [] custList;

    return 0;
}

void printHeader(ostream& out)
{
    out << "********************************" << endl;
    out << "********** ODUrentals **********" << endl;
    out << "********************************" << endl;
    out << endl << endl;
}