#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

class Person
{
    private:
        std::string _firstname;
        std::string _lastname;
        std::string _car;

    public:
        //constructors
        Person();
        Person(std::string fname, std::string lname, std::string car);

        //destructor?

        //manipulators
        std::string getFName() { return _firstname; };
        std::string getLName() { return _lastname; };
        std::string getCar() { return _car; };

        void setFName(std::string fname) { _firstname = fname};
        void setLName(std::string lname) { _lastname = lname };
        void setCar(std::string car) { _car = car };
};

#endif //__PERSON_H__