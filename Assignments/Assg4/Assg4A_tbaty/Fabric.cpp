#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

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

void Fabric::sortAscByCost(Fabric *list, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i+1; j < count; j++)
        {
            if (list[j].price.lessThan(list[i].price))//member function comparison call
            {
                Fabric temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

Fabric* readInput(ifstream& infile, Fabric *list, int& count)
{
    infile >> count;

    list = new Fabric[count];//implicit call to default constructor
    int i = 0;
    while (!infile.eof())
    {
        string nameIn;
        string colorIn;
        int onHandIn;
        double priceIn;

        infile >> nameIn >> colorIn >> onHandIn >> priceIn;

        list[i] = Fabric(nameIn, colorIn, onHandIn, priceIn);

        infile >> ws; //eat up any whitespace remaining on line/file
        i++;
    }
    list->sortAscByCost(list, count);
    return list;
}

void print(Fabric list[], int count)
{
    cout << setw(50) << setfill('=') << " " << endl
         << setw(20) << setfill(' ') << " " << "Fabric" << endl
         << setw(50) << setfill('=') << " " << endl;

    cout << setw(10) << setfill(' ') << " " << "Name"
         << setw(9) << right << " | " << "Color"
         << setw(4) << " | " << "Inventory"
         << setw(3) << " | " << " Cost" << endl;

    cout << setw(80) << setfill('-') << " " << endl;

    for (int i = 0; i < count; i++)
    {
        cout << setfill(' ') << fixed << showpoint << setprecision(2);

        cout << setw(20) << left << list[i].name << " | "
             << setw(6) << right << list[i].color << " | "
             << setw(9) << list[i].amtInStock << " | "
             << setw(6) << toDouble(list[i].price) << endl;
    }

   cout << endl << endl;
};

void write(ofstream& outfile, Fabric *list, int count)
{
    outfile << setw(50) << setfill('=') << " " << endl
         << setw(20) << setfill(' ') << " " << "Fabric" << endl
         << setw(50) << setfill('=') << " " << endl;

    outfile << setw(10) << setfill(' ') << " " << "Name"
         << setw(9) << right << " | " << "Color"
         << setw(4) << " | " << "Inventory"
         << setw(3) << " | " << " Cost" << endl;

    outfile << setw(80) << setfill('-') << " " << endl;

    for (int i = 0; i < count; i++)
    {
        outfile << setfill(' ') << fixed << showpoint << setprecision(2);

        outfile << setw(20) << left << list[i].name << " | "
             << setw(6) << right << list[i].color << " | "
             << setw(9) << list[i].amtInStock << " | "
             << setw(6) << toDouble(list[i].price) << endl;
    }

   outfile << endl << endl;

}