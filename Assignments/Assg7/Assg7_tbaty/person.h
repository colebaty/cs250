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
        //no pointers, so no need - compiler auto generates

        //manipulators
        std::string getFName() const { return _firstname; };
        std::string getLName() const { return _lastname; };
        std::string getCar() const { return _car; };

        void setFName(std::string fname) { _firstname = fname; };
        void setLName(std::string lname) { _lastname = lname; };
        void setCar(std::string car) { _car = car; };

        void print(std::ostream& out) const;
};

inline
std::ostream& operator<< (std::ostream& out, const Person& p)
{
    p.print(out);
    return out;
}

#endif //__PERSON_H__