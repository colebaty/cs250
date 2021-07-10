#ifndef __BOOK_H__
#define __BOOK_H__

#include "DecorationStoreUtilities.h"

struct Book
{
    Book();
    Book(std::string bName, int bIsHardcover, int bNumPages, 
         double bPrice, int bAmtInStock, std::string bDatePublished);
         
    std::string name;
    int isHarcover;
    int numPages;
    Money price;
    int amtInStock;
    Date datePublished;

    void sortAscByCost(Book *list, int count);

};

Book* readInput(ifstream& infile, Book *list, int& count);
void print(Book *list, int count);
void write(ofstream& outfile, Book *list, int count);

#endif // __BOOK_H__