#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

#include "person.h"
#include <string>

/**
 * @brief Class for storing customer information
 * 
 */
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
        /**
         * @brief Returns the balance on the Customer's account. A negative balance
         * indicates overpayment by the customer; i.e. the customer is owed a refund.
         * Values are automatically rounded IAW iomanip::setprecision()
         * 
         * @return double the customer's balance
         */
        double getBalance() const { return _balance; };
        /**
         * @brief Returns whether the customer is enrolled in the Preferred 
         * Customer program
         * 
         * @return true the customer is enrolled
         * @return false the customer is not enrolled
         */
        bool isPreferred() const { return _isPreferred; };

        /**
         * @brief set the customer's balance to the indicated amount
         * 
         * @param balance the customer's balance
         */
        void setBalance(double balance) { _balance = balance; };
        /**
         * @brief Set whether the customer is enrolled in the Preferred Customer
         * Program.
         * 
         * @param isPreferred 
         */
        void setPreferred(bool isPreferred) { _isPreferred = isPreferred; };

        void print(std::ostream& out) const;
};

inline
std::ostream& operator<< (std::ostream& out, const Customer& c)
{
    c.print(out);
    return out;
}

/**
 * @brief Creat a dynamic array of Customers from the given istream
 * 
 * @param in the file containing Customer information
 * @param size the size of the dynamic array
 * @return Customer* a pointer to the dynamic array
 */
Customer* readCustomers(std::istream& in, int& size);

/**
 * @brief print a list of all the customers IAW the assignment instructions
 * 
 * @param out the stream to print to
 * @param list the list containing the information
 * @param size the size of the list
 */
void printCustomers(std::ostream& out, Customer *list, const int& size);

#endif //__CUSTOMER_H__