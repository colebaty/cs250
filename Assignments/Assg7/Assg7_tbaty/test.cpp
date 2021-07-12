#include <iostream>
#include "person.h"

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
    
    return 0;
}
