#ifndef __FABRIC_H__
#define __FABRIC_H__

#include "DecorationStoreUtilities.h"

struct Fabric
{
    Fabric();
    Fabric(std::string fName, std::string fColor, 
            int fAmtInStock, double fPrice);

    std::string name;
    std::string color;
    int amtInStock;
    Money price;

    void sortAscByCost(Fabric *list, int count);
};

Fabric* readInput(ifstream& infile, Fabric *list, int& count);
void print(Fabric *list, int count);
void write(ofstream& outfile, Fabric *list, int count);

#endif // __FABRIC_H__