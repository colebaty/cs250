#include <iostream>
#include "person.h"
#include "staff.h"
#include "customer.h"

using namespace std;

int main()
{
    cout << "*********************************" << endl;
    cout << "********* Person Tests **********" << endl;
    cout << "*********************************" << endl;

    Person blank = Person();
    Person notBlank = Person("cole", "baty", "chevy silverado");
    Person *personPtr = new Person("pointer", "poindexter", "tesla model x, duh");

    cout << "blank person: " << blank << endl;
    cout << "not blank person: " << notBlank << endl;
    cout << "person pointer: " << *personPtr << endl;

    cout << "getters:" << endl
         << "\tgetFName: " << notBlank.getFName() << endl
         << "\tgetLName: " << notBlank.getLName() << endl
         << "\tgetCar: " << notBlank.getCar() << endl;

    cout << "set blank info" << endl;

    blank.setFName("Corey");
    blank.setLName("White");
    blank.setCar("Kia Sorento");

    cout << "blank person after calling setters: " << blank << endl;

    cout << "changing pointer person's car" << endl;
    personPtr->setCar("tesla roadster, but like the one that went to space");
    cout << "person pointer after change: " << *personPtr << endl;
    
    delete personPtr;
    
    cout << "*********************************" << endl;
    cout << "********* Staff Tests ***********" << endl;
    cout << "*********************************" << endl;

    Staff blankStaff = Staff();
    Staff notBlankStaff = Staff("ashley", "taylor", "mazda something", 68000);
    Staff *staffPtr = new Staff("Jarrod", "Taylor", "Mazda dogmobile", 54000);

    cout << "blankStaff staff: " << blankStaff << endl;
    cout << "not blankStaff staf: " << notBlankStaff << endl;
    cout << "staff pointer: " << *staffPtr << endl;

    cout << "getters:" << endl
         << "\tgetFName: " << notBlankStaff.getFName() << endl
         << "\tgetLName: " << notBlankStaff.getLName() << endl
         << "\tgetCar: " << notBlankStaff.getCar() << endl
         << "\tgetSalary: " << notBlankStaff.getSalary() << endl;

    cout << "changing staffPtr's salary" << endl;
    staffPtr->setSalary(69000);
    cout << "staffPtr after change: " << *staffPtr << endl;

    delete staffPtr;

    cout << "*********************************" << endl;
    cout << "******* Customer Tests **********" << endl;
    cout << "*********************************" << endl;

    Customer blankCustomer = Customer();
    Customer notBlankCustomer = Customer("petra", "schwarznau", "Volkswagen Golf", 68000, true);
    Customer *customerPtr = new Customer("werner", "Kraft", "Mercedes 900 Series", 54000);//tests default preferred status

    cout << "blank customer: " << blankCustomer << endl;
    cout << "not blank customer: " << notBlankCustomer << endl;
    cout << "customer pointer: " << *customerPtr << endl;

    cout << "getters:" << endl
         << "\tgetFName: " << notBlankCustomer.getFName() << endl
         << "\tgetLName: " << notBlankCustomer.getLName() << endl
         << "\tisPreferred: " << notBlankCustomer.isPreferred() << endl
         << "\tgetCar: " << notBlankCustomer.getCar() << endl
         << "\tgetBalance: " << notBlankCustomer.getBalance() << endl;
    
    cout << "changing customerPtr's balance, preferred status" << endl;
    customerPtr->setBalance(696969.6969);//also will test implicit rounding called by operator<<
    customerPtr->setPreferred(true);
    cout << "customerPtr after changes: " << *customerPtr << endl;


    return 0;
}
