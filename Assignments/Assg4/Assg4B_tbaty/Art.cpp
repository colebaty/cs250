#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

#include "Art.h"

using namespace std;

Art::Art()
{
    name = "";
    price = toMoney(0.0);
    amtInStock = 0;
    dateCreated = toDate("0:0:0");
    dimensions = toDimensions("0:0:0");
}

Art::Art(std::string aName, double aPrice, int aAmtInStock,
    string aDateCreated, string aDimension)
{
    name = aName;
    price = toMoney(aPrice);
    amtInStock = aAmtInStock;
    dateCreated = toDate(aDateCreated);
    dimensions = toDimensions(aDimension);
}

void readInput(vector<Art>& v)
{
    ifstream infile("Art.txt");

    //read first line - not needed for vectors
    int garbage;
    infile >> garbage;

    while (!infile.eof())
    {
        string nameIn;
        double priceIn;
        int onHandIn;
        string dateIn;
        string dimensionsIn;

        infile >> nameIn >> priceIn >> onHandIn >> dateIn >> dimensionsIn;

        v.push_back(Art(nameIn, priceIn, onHandIn, dateIn, dimensionsIn));

        infile >> ws; //eat up any whitespace remaining on line/file

    }

    sortAscByCost(v);
    infile.close();
}

void print(std::vector<Art> v)
{
    cout << "print: v.size() = " << v.size() << endl;

    cout << setw(50) << setfill('=') << " " << endl
         << setw(22) << setfill(' ') << " " << "Art" << endl
         << setw(50) << setfill('=') << " " << endl;

    cout << setw(9) << setfill(' ') << " " << "Name"
         << setw(10) << right << " | " << "    Cost"
         << setw(5) << " | " << " Inventory"
         << setw(5) << " | " << "Date Created"
         << setw(2) << " | " << "Dimensions" << endl;

    cout << setw(80) << setfill('-') << " " << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << setfill(' ') << fixed << showpoint << setprecision(2);

        cout << setw(20) << left << v[i].name << " | "
             << setw(10) << right << toDouble(v[i].price) << " | "
             << setw(12) << v[i].amtInStock << " | "
             << setw(12) << toString(v[i].dateCreated) << " | "
             << setw(10) << toString(v[i].dimensions) << endl;
    }

    cout << endl << endl;
}

void write(ofstream& outfile, vector<Art> v)
{
    outfile << setw(50) << setfill('=') << " " << endl
         << setw(22) << setfill(' ') << " " << "Art" << endl
         << setw(50) << setfill('=') << " " << endl;

    outfile << setw(9) << setfill(' ') << " " << "Name"
         << setw(10) << right << " | " << "    Cost"
         << setw(5) << " | " << " Inventory"
         << setw(5) << " | " << "Date Created"
         << setw(2) << " | " << "Dimensions" << endl;

    outfile << setw(80) << setfill('-') << " " << endl;

    for (int i = 0; i < v.size(); i++)
    {
        outfile << setfill(' ') << fixed << showpoint << setprecision(2);

        outfile << setw(20) << left << v[i].name << " | "
             << setw(10) << right << toDouble(v[i].price) << " | "
             << setw(12) << v[i].amtInStock << " | "
             << setw(12) << toString(v[i].dateCreated) << " | "
             << setw(10) << toString(v[i].dimensions) << endl;
    }

    outfile << endl << endl;
}
