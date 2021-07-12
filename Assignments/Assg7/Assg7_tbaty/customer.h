#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include "person.h"
#include <string>

class Customer : public Person
{
    private:
        double _balance;
        bool _isPreferred;

    public:
        //constructors
        Customer();
        Customer(std::string fname, std::string lname, std::string car, 
                 double balance = 0.0, bool isPreferred = false);

        //manipulators
        double getBalance() const { return _balance; };
        bool isPreferred() const { return _isPreferred; };

        void setBalance(double balance) { _balance = balance; };
        void setPreferred(bool isPreferred) { _isPreferred = isPreferred; };

        void print(std::ostream& out) const;
};

inline
std::ostream& operator<< (std::ostream& out, const Customer& c)
{
    c.print(out);
    return out;
}

#endif //__CUSTOMER_H__