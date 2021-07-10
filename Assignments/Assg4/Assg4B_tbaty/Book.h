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
};

void readInput(std::vector<Book>& v);
void print(std::vector<Book> v);
void write(std::ofstream& outfile, std::vector<Book> v);
#endif // __BOOK_H__