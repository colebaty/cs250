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
};

void readInput(std::vector<Fabric>& v);
void print(std::vector<Fabric> v);
void write(std::ofstream& outfile, std::vector<Fabric> v);
#endif // __FABRIC_H__