#ifndef __FURNITURE_H__
#define __FURNITURE_H__

#include "DecorationStoreUtilities.h"

struct Furniture
{
    Furniture();
    Furniture(std::string fName, std::string fColor, int fAmtInStock,
              std::string fDateCreated, double fPrice);

    std::string name;
    std::string color;
    int amtInStock;
    Date dateCreated;
    Money price;
};

void readInput(std::vector<Furniture>& v);
void print(std::vector<Furniture> v);
void write(std::ofstream& outfile, std::vector<Furniture> v);
#endif // __FURNITURE_H__