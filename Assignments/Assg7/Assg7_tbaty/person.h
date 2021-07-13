#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>

/**
 * @brief Base type for Assignment 7.  Customers and Staff each share name and
 * car information. Extending this base class saves having to repeat information
 * in the derived classes.
 * 
 */
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

        /**
         * @brief Returns the first name
         * 
         * @return std::string the first name
         */
        std::string getFName() const { return _firstname; };

        /**
         * @brief Returns the last name
         * 
         * @return std::string the last name
         */
        std::string getLName() const { return _lastname; };

        /**
         * @brief Returns the car information
         * 
         * @return std::string the car information
         */
        std::string getCar() const { return _car; };

        /**
         * @brief set the first name
         * 
         * @param fname the first name
         */
        void setFName(std::string fname) { _firstname = fname; };

        /**
         * @brief set the last name
         * 
         * @param fname the last name
         */
        void setLName(std::string lname) { _lastname = lname; };

        /**
         * @brief set the car information
         * 
         * @param car the car information
         */
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