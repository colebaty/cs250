#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Book.h"

using namespace std;

Book::Book()
{
    name = "";
    isHarcover = 0;
    numPages = 0;
    price = toMoney(0.0);
    amtInStock = 0;
    datePublished = toDate("0:0:0");
}

Book::Book(std::string bName, int bIsHardcover, int bNumPages, 
        double bPrice, int bAmtInStock, std::string bDatePublished)
{
    name = bName;
    isHarcover = bIsHardcover;
    numPages = bNumPages;
    price = toMoney(bPrice);
    amtInStock = bAmtInStock;
    datePublished = toDate(bDatePublished);
}

void readInput(std::vector<Book>& v)
{
    ifstream infile("Book.txt");

    //read first line - not needed for vectors
    int garbage;
    infile >> garbage;

    while (!infile.eof())
    {
        string nameIn;
        int isHardcoverIn;
        int numPagesIn;
        double priceIn;
        int onHandIn;
        string dateIn;

        infile >> nameIn >> isHardcoverIn >> numPagesIn >> priceIn 
               >> onHandIn >> dateIn;

        v.push_back(Book(nameIn, isHardcoverIn, numPagesIn, priceIn, onHandIn, dateIn));

        infile >> ws; //eat up any whitespace remaining on line/file
    }
    sortAscByCost(v);
}

void print(std::vector<Book> v)
{
    cout << setw(50) << setfill('=') << " " << endl
         << setw(20) << setfill(' ') << " " << "Book" << endl
         << setw(50) << setfill('=') << " " << endl;

    cout << setw(10) << setfill(' ') << " " << "Name"
         << setw(9) << right << " | " << "Hardcover"
         << setw(4) << " | " << "Page Count"
         << setw(3) << " | " << " Cost"
         << setw(4) << " | " << "Inventory"
         << setw(5) << " | " << "Date Published" << endl;

    cout << setw(90) << setfill('-') << " " << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << setfill(' ') << fixed << showpoint << setprecision(2);

        cout << setw(20) << left << v[i].name << " | "
             << setw(10) << right << v[i].isHarcover << " | "    
             << setw(10) << v[i].numPages << " | "
             << setw(6) << toDouble(v[i].price) << " | "
             << setw(11) << v[i].amtInStock << " | "
             << setw(12) << toString(v[i].datePublished) << endl;
    }

   cout << endl << endl;
}

void write(std::ofstream& outfile, std::vector<Book> v)
{
    outfile << setw(50) << setfill('=') << " " << endl
         << setw(20) << setfill(' ') << " " << "Book" << endl
         << setw(50) << setfill('=') << " " << endl;

    outfile << setw(10) << setfill(' ') << " " << "Name"
         << setw(9) << right << " | " << "Hardcover"
         << setw(4) << " | " << "Page Count"
         << setw(3) << " | " << " Cost"
         << setw(4) << " | " << "Inventory"
         << setw(5) << " | " << "Date Published" << endl;

    outfile << setw(90) << setfill('-') << " " << endl;

    for (int i = 0; i < v.size(); i++)
    {
        outfile << setfill(' ') << fixed << showpoint << setprecision(2);

        outfile << setw(20) << left << v[i].name << " | "
             << setw(10) << right << v[i].isHarcover << " | "    
             << setw(10) << v[i].numPages << " | "
             << setw(6) << toDouble(v[i].price) << " | "
             << setw(11) << v[i].amtInStock << " | "
             << setw(12) << toString(v[i].datePublished) << endl;
    }

   outfile << endl << endl;
}
