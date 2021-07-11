#ifndef __ART_H__
#define __ART_H__

#include "DecorationStoreUtilities.h"

struct Art
{
    //constructors
    Art();
    Art(std::string aName, double aPrice, int aAmtInStock,
        string aDateCreated, string aDimension);

    //member variables
    std::string name;
    Money price;
    int amtInStock;
    Date dateCreated;
    Dimensions dimensions;

    //member functions
    void sortAscByCost(Art *list, int count);
};

Art* readInput(std::ifstream& infile, Art *list, int& count);
void print(Art *list, int count);
void write(ofstream& outfile, Art *list, int count);
#endif // __ART_H__
