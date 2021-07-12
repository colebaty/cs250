#include <iostream>
#include "person.h"
#include "staff.h"

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

    return 0;
}
