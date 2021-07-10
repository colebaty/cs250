#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

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

void readInput(std::vector<Furniture>& v)
{
    ifstream infile("Furniture.txt");

    //read first line - not needed for vectors
    int garbage;
    infile >> garbage;

    while (!infile.eof())
    {
        string nameIn;
        string colorIn;
        int onHandIn;
        string dateIn;
        double priceIn;

        infile >> nameIn >> colorIn >> onHandIn >> dateIn >> priceIn;

        v.push_back(Furniture(nameIn, colorIn, onHandIn, dateIn, priceIn));

        infile >> ws; //eat up any whitespace remaining on line/file
    }

    sortAscByCost(v);
}

void print(std::vector<Furniture> v)
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

    for (int i = 0; i < v.size(); i++)
    {
        cout << setfill(' ') << fixed << showpoint << setprecision(2);

        cout << setw(20) << left << v[i].name << " | "
             << setw(8) << right << v[i].color << " | "
             << setw(12) << v[i].amtInStock << " | "
             << setw(12) << toString(v[i].dateCreated) << " | "
             << setw(10) << toDouble(v[i].price) << endl;
    }

    cout << endl << endl;
}

void write(std::ofstream& outfile, std::vector<Furniture> v)
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

    for (int i = 0; i < v.size(); i++)
    {
        outfile << setfill(' ') << fixed << showpoint << setprecision(2);

        outfile << setw(20) << left << v[i].name << " | "
             << setw(8) << right << v[i].color << " | "
             << setw(12) << v[i].amtInStock << " | "
             << setw(12) << toString(v[i].dateCreated) << " | "
             << setw(10) << toDouble(v[i].price) << endl;
    }

    outfile << endl << endl;
}
