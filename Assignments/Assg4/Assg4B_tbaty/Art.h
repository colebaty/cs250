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
};

void readInput(std::vector<Art>& v);
void print(std::vector<Art> v);
void write(std::ofstream& outfile, std::vector<Art> v);
#endif // __ART_H__