#include <iostream>
#include <fstream>
#include <sstream>

#include "staff.h"
#include "customer.h"

using namespace std;

Staff* readStaff(istream& in, int& size);
Customer* readCustomers(istream& in, int& size);

void printStaffHeader();
void printCustomerHeader();

template <class C>
void printList(ostream& out, C* list, const int& size);


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

    // #ifdef DEBUG
    //     cerr << "staffList address: " << &staffList << endl;
    //     cerr << "custList address: " << &custList << endl;
    // #endif

    int noStaff, noCust;
    noStaff = noCust = 0;

    //read staff.txt
    #ifdef DEBUG
        cerr << "======== populating staffList ======== " << endl;
    #endif
    staffList = readStaff(staffIn, noStaff);
    

    //read customers.txt
    #ifdef DEBUG
        cerr << "======== populating custList ======== " << endl;
    #endif
    custList = readCustomers(customersIn, noCust);

    #ifdef DEBUG
        cerr << "staffList[0]: " << staffList[0] << endl;
        cerr << "custList[0]: " << custList[0] << endl;
    #endif

    //close input files
    //print data
        //print program header
        //print staff header
            //print staff data
        //print customer header
            //print customer data
    delete [] staffList;
    delete [] custList;

    return 0;
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

Customer* readCustomers(istream& in, int& size)
{
    // read first line for number of staff
    in >> size >> ws;
    // in >> size;

    //create dynamic array of staff with number read from first line
    Customer *list = new Customer[size];

    // read each remaining line; populate array
    char fname[50];
    char lname[50];
    char car[50];
    int isPreferred;
    double balance = 0.0;

    string line = "";
    getline(in, line);

    int i = 0;
    while (in && i < size)
    {
        #ifdef DEBUG
            cerr << "line: " << line << endl;
        #endif

        istringstream linein(line);
        linein.get(fname, 50, ' ');
        linein >> ws;//advance linein; get() does not extract delimiter
        linein.get(lname, 50, ' ');
        linein >> ws;
        linein >> isPreferred;
        linein.get(car, 50, ' ');
        linein >> ws;
        linein >> balance;

        #ifdef DEBUG
            cerr << "list[" << i << "]:" << endl
                 << "fname: " << fname << endl
                 << "lname: " << lname << endl
                 << "isPreferred: " << isPreferred << endl
                 << "car: " << car << endl
                 << "balance: " << balance << endl;
        #endif
        
        list[i] = Customer(string(fname), string(lname), string(car), 
                                  (isPreferred == 1), balance);
        #ifdef DEBUG
            cerr << "list[" << i << "]: " << list[i] << endl << endl;
        #endif
        getline(in, line);
        i++;
    }

    return list;
}