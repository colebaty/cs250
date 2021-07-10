#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

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

void Art::sortAscByCost(Art *list, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i+1; j < count; j++)
        {
            if (list[j].price.lessThan(list[i].price))//member function comparison call
            {
                Art temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

Art* readInput(ifstream& infile, Art *list, int& count)
{
    infile >> count;

    list = new Art[count];//implicit call to default constructors
    int i = 0;
    while (!infile.eof())
    {
        string nameIn;
        double priceIn;
        int onHandIn;
        string dateIn;
        string dimensionsIn;

        infile >> nameIn >> priceIn >> onHandIn >> dateIn >> dimensionsIn;

        //constructor populates memory address of list[i] with parameters.
        //initially, i suspected this would create a whole new memory address
        //and sub that in place of list[i], but i confirmed that the 
        //address of list[i] doesn't change. neat.
        list[i] = Art(nameIn, priceIn, onHandIn, dateIn, dimensionsIn);

        infile >> ws; //eat up any whitespace remaining on line/file
        i++;
    }

    //this is a new one for me; calling a member function on the member itself
    // but it works so ¯\_(ツ)_/¯
    list->sortAscByCost(list, count);
    return list;
}

void print(Art *list, int count)
{
    cout << setw(50) << setfill('=') << " " << endl
         << setw(22) << setfill(' ') << " " << "Art" << endl
         << setw(50) << setfill('=') << " " << endl;

    cout << setw(9) << setfill(' ') << " " << "Name"
         << setw(10) << right << " | " << "    Cost"
         << setw(5) << " | " << " Inventory"
         << setw(5) << " | " << "Date Created"
         << setw(2) << " | " << "Dimensions" << endl;

    cout << setw(80) << setfill('-') << " " << endl;

    for (int i = 0; i < count; i++)
    {
        cout << setfill(' ') << fixed << showpoint << setprecision(2);

        cout << setw(20) << left << list[i].name << " | "
             << setw(10) << right << toDouble(list[i].price) << " | "
             << setw(12) << list[i].amtInStock << " | "
             << setw(12) << toString(list[i].dateCreated) << " | "
             << setw(10) << toString(list[i].dimensions) << endl;
    }

    cout << endl << endl;
}

void write(ofstream& outfile, Art *list, int count)
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

    for (int i = 0; i < count; i++)
    {
        outfile << setfill(' ') << fixed << showpoint << setprecision(2);

        outfile << setw(20) << left << list[i].name << " | "
             << setw(10) << right << toDouble(list[i].price) << " | "
             << setw(12) << list[i].amtInStock << " | "
             << setw(12) << toString(list[i].dateCreated) << " | "
             << setw(10) << toString(list[i].dimensions) << endl;
    }

    outfile << endl << endl;
}
