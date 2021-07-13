#include "customer.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void printCustomerHeader(ostream& out);

Customer::Customer()
    : Person()
{
    setBalance(0.0);
    setPreferred(false);
}

Customer::Customer(string fname, string lname, string car, double balance, bool isPreferred)
    : Person(fname, lname, car)
{
    setBalance(balance);
    setPreferred(isPreferred);
}

void Customer::print(ostream& out) const
{
    cout << Person::getFName() + " " + Person::getLName() << " " 
         << isPreferred() << " " 
         << Person::getCar() << " "
         << fixed << showpoint << setprecision(2) << getBalance();
}

Customer* readCustomers(istream& in, int& size)
{
    // read first line for number of staff
    in >> size >> ws;
    // in >> size;

    //create dynamic array of staff with number read from first line
    Customer *list = new Customer[size];

    // read each remaining line; populate array
    string line = "";
    getline(in, line);

    int i = 0;
    while (in && i < size)
    {
        #ifdef DEBUG
            cerr << "line: " << line << endl;
        #endif

		char fname[50];
		char lname[50];
		char car[50];
		int isPreferred;
		double balance = 0.0;

        istringstream linein(line);
        linein.get(fname, 50, ' ');
        linein >> ws;//advance linein; get() does not extract delimiter
        linein.get(lname, 50, ' ');
        linein >> ws;
        linein >> isPreferred;
        linein >> ws;
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
                                  balance, (isPreferred == 1));
        #ifdef DEBUG
            cerr << "list[" << i << "]: " << list[i] << endl << endl;
        #endif
        getline(in, line);
        i++;
    }

    return list;
}

void printCustomers(std::ostream& out, Customer *list, const int& size)
{
    printCustomerHeader(out);
    for (int i = 0; i < size; i++)
    {
        out << left 
            << setw(20) << list[i].getFName() + " " + list[i].getLName() << "|  ";
        list[i].isPreferred() ? out << setw(12) << "   Y" << "|  "
                              : out << setw(12) << "   N" << "|  ";
        out << setw(18) << list[i].getCar() << "|  "
            << right << setw(8) << fixed <<setprecision(2) << list[i].getBalance() << endl;
    }

    out << endl;
}

void printCustomerHeader(ostream& out)
{
    out << "***********************************" << endl;
    out << "********** Customer List **********" << endl;
    out << "***********************************" << endl << endl;

    out << left 
        << setw(20) << "Name" << "|  " 
        << setw(12) << "Preferred" << "|  " 
        << setw(18) << "Car" << "|  " 
        << setw(20) << "Balance" << endl;

    out << right << setfill('-') << setw(70) << " " << endl;
    out << setfill(' ');

}