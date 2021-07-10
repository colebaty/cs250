#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

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

void Book::sortAscByCost(Book *list, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i+1; j < count; j++)
        {
            if (list[j].price.lessThan(list[i].price))//member function comparison call
            {
                Book temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

Book* readInput(ifstream& infile, Book *list, int& count)
{
    infile >> count;

    list = new Book[count];//implicit call to default constructor
    int i = 0;
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

        list[i] = Book(nameIn, isHardcoverIn, numPagesIn, 
                       priceIn, onHandIn, dateIn);

        infile >> ws; //eat up any whitespace remaining on line/file
        i++;
    }
    list->sortAscByCost(list, count);
    return list;
}

void print(Book *list, int count)
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

    for (int i = 0; i < count; i++)
    {
        cout << setfill(' ') << fixed << showpoint << setprecision(2);

        cout << setw(20) << left << list[i].name << " | "
             << setw(10) << right << list[i].isHarcover << " | "    
             << setw(10) << list[i].numPages << " | "
             << setw(6) << toDouble(list[i].price) << " | "
             << setw(11) << list[i].amtInStock << " | "
             << setw(12) << toString(list[i].datePublished) << endl;
    }

   cout << endl << endl;
}

void write(ofstream& outfile, Book *list, int count)
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

    for (int i = 0; i < count; i++)
    {
        outfile << setfill(' ') << fixed << showpoint << setprecision(2);

        outfile << setw(20) << left << list[i].name << " | "
             << setw(10) << right << list[i].isHarcover << " | "    
             << setw(10) << list[i].numPages << " | "
             << setw(6) << toDouble(list[i].price) << " | "
             << setw(11) << list[i].amtInStock << " | "
             << setw(12) << toString(list[i].datePublished) << endl;
    }

   outfile << endl << endl;
}
