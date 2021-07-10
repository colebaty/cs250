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

    void sortAscByCost(Furniture *list, int count);
};

Furniture* readInput(ifstream& infile, Furniture *list, int& count);
void print(Furniture *list, int count);
void write(ofstream& outfile, Furniture *list, int count);

#endif // __FURNITURE_H__