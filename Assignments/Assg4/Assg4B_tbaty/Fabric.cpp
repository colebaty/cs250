#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Fabric.h"

using namespace std;

Fabric::Fabric()
{
    name = "";
    color = "";
    amtInStock = 0;
    price = toMoney(0.0);

}

Fabric::Fabric(std::string fName, std::string fColor, 
                int fAmtInStock, double fPrice)
{
    name = fName;
    color = fColor;
    amtInStock = fAmtInStock;
    price = toMoney(fPrice);
}

void readInput(std::vector<Fabric>& v)
{
    ifstream infile("Fabric.txt");

    //read first line - not needed for vectors
    int garbage;
    infile >> garbage;

    while (!infile.eof())
    {
        string nameIn;
        string colorIn;
        int onHandIn;
        double priceIn;

        infile >> nameIn >> colorIn >> onHandIn >> priceIn;

        v.push_back(Fabric(nameIn, colorIn, onHandIn, priceIn));

        infile >> ws; //eat up any whitespace remaining on line/file
    }
    sortAscByCost(v);
}

void print(std::vector<Fabric> v)
{
    cout << setw(50) << setfill('=') << " " << endl
         << setw(20) << setfill(' ') << " " << "Fabric" << endl
         << setw(50) << setfill('=') << " " << endl;

    cout << setw(10) << setfill(' ') << " " << "Name"
         << setw(9) << right << " | " << "Color"
         << setw(4) << " | " << "Inventory"
         << setw(3) << " | " << " Cost" << endl;

    cout << setw(80) << setfill('-') << " " << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << setfill(' ') << fixed << showpoint << setprecision(2);

        cout << setw(20) << left << v[i].name << " | "
             << setw(6) << right << v[i].color << " | "
             << setw(9) << v[i].amtInStock << " | "
             << setw(6) << toDouble(v[i].price) << endl;
    }

   cout << endl << endl;
};

void write(std::ofstream& outfile, std::vector<Fabric> v)
{
    outfile << setw(50) << setfill('=') << " " << endl
         << setw(20) << setfill(' ') << " " << "Fabric" << endl
         << setw(50) << setfill('=') << " " << endl;

    outfile << setw(10) << setfill(' ') << " " << "Name"
         << setw(9) << right << " | " << "Color"
         << setw(4) << " | " << "Inventory"
         << setw(3) << " | " << " Cost" << endl;

    outfile << setw(80) << setfill('-') << " " << endl;

    for (int i = 0; i < v.size(); i++)
    {
        outfile << setfill(' ') << fixed << showpoint << setprecision(2);

        outfile << setw(20) << left << v[i].name << " | "
             << setw(6) << right << v[i].color << " | "
             << setw(9) << v[i].amtInStock << " | "
             << setw(6) << toDouble(v[i].price) << endl;
    }

   outfile << endl << endl;

}