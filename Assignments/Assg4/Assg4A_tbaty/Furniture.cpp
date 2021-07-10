#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

#include "Furniture.h"

using namespace std;

Furniture::Furniture()
{
    name = "";
    color = "";
    amtInStock = 0;
    dateCreated = toDate("0:0:0");
    price = toMoney(0.0);
}

Furniture::Furniture(std::string fName, std::string fColor, int fAmtInStock,
            std::string fDateCreated, double fPrice)
{
    name = fName;
    color = fColor;
    amtInStock = fAmtInStock;
    dateCreated = toDate(fDateCreated);
    price = toMoney(fPrice);
}

void Furniture::sortAscByCost(Furniture *list, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i+1; j < count; j++)
        {
            if (list[j].price.lessThan(list[i].price))//member function comparison call
            {
                Furniture temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

Furniture* readInput(ifstream& infile, Furniture *list, int& count)
{
    infile >> count;

    list = new Furniture[count];//implicit call to default constructor
    int i = 0;
    while (!infile.eof())
    {
        string nameIn;
        string colorIn;
        int onHandIn;
        string dateIn;
        double priceIn;

        infile >> nameIn >> colorIn >> onHandIn >> dateIn >> priceIn;

        list[i] = Furniture(nameIn, colorIn, onHandIn, dateIn, priceIn);

        infile >> ws; //eat up any whitespace remaining on line/file
        i++;
    }


    list->sortAscByCost(list, count);
    return list;
}

void print(Furniture *list, int count)
{
    cout << setw(50) << setfill('=') << " " << endl
         << setw(20) << setfill(' ') << " " << "Furniture" << endl
         << setw(50) << setfill('=') << " " << endl;
    
    cout << setw(9) << setfill(' ') << " " << "Name"
         << setw(10) << right << " | " << " Color "
         << setw(4) << " | " << "Inventory"
         << setw(6) << " | " << "Date Created"
         << setw(2) << " | " << "    Cost" << endl;

    cout << setw(80) << setfill('-') << " " << endl;

    for (int i = 0; i < count; i++)
    {
        cout << setfill(' ') << fixed << showpoint << setprecision(2);

        cout << setw(20) << left << list[i].name << " | "
             << setw(8) << right << list[i].color << " | "
             << setw(12) << list[i].amtInStock << " | "
             << setw(12) << toString(list[i].dateCreated) << " | "
             << setw(10) << toDouble(list[i].price) << endl;
    }

    cout << endl << endl;
}

void write(ofstream& outfile, Furniture *list, int count)
{
    outfile << setw(50) << setfill('=') << " " << endl
         << setw(20) << setfill(' ') << " " << "Furniture" << endl
         << setw(50) << setfill('=') << " " << endl;
    
    outfile << setw(9) << setfill(' ') << " " << "Name"
         << setw(10) << right << " | " << " Color "
         << setw(4) << " | " << "Inventory"
         << setw(6) << " | " << "Date Created"
         << setw(2) << " | " << "    Cost" << endl;

    outfile << setw(80) << setfill('-') << " " << endl;

    for (int i = 0; i < count; i++)
    {
        outfile << setfill(' ') << fixed << showpoint << setprecision(2);

        outfile << setw(20) << left << list[i].name << " | "
             << setw(8) << right << list[i].color << " | "
             << setw(12) << list[i].amtInStock << " | "
             << setw(12) << toString(list[i].dateCreated) << " | "
             << setw(10) << toDouble(list[i].price) << endl;
    }

    outfile << endl << endl;
}
