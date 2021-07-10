//standard libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>

//user-defined modules
#include "Art.h"
#include "Fabric.h"
#include "Furniture.h"
#include "Book.h"

using namespace std;

//function prototypes
void printHead();
void writeOutput(Furniture *furnitureList, int furnitureCount,
                 Art *artList, int artCount,
                 Book *bookList, int bookCount,
                 Fabric *fabricList, int fabricCount);
void writeHead(ofstream& outfile);

/* 
    re-using code from Assg1.  
        - changed `main` so that it is no-longer menu-driven.  
        - changed all struct arrays to be dynamically allocated.
 */
int main()
{
    //print header
    printHead();

    //declare, initialize, validate variables
    ifstream furnitureIn("Furniture.txt");
    ifstream artIn("Art.txt");
    ifstream fabricIn("Fabric.txt");
    ifstream bookIn("Book.txt");
    if (!furnitureIn || !artIn || !fabricIn || !bookIn)
    {
        cerr << "Error: file not found" << endl;
        return 1;
    }

    int furnitureCount = 0;
    int artCount = 0;
    int fabricCount = 0;
    int bookCount = 0;

    Furniture *furnitureList;
    Art *artList;
    Fabric *fabricList;
    Book *bookList;

    //read each file into an array 
    //each `readInput` function initializes dynamic arrays with the number 
    //on the first line of respective input files; this is an implicit call 
    //to the default constructor of each struct
    furnitureList = readInput(furnitureIn, furnitureList, furnitureCount);
    artList = readInput(artIn, artList, artCount);
    fabricList = readInput(fabricIn, fabricList, fabricCount);
    bookList = readInput(bookIn, bookList, bookCount);

    print(furnitureList, furnitureCount);
    print(artList, artCount);
    print(bookList, bookCount);
    print(fabricList, fabricCount);

    writeOutput(furnitureList, furnitureCount, artList, artCount,
                bookList, bookCount, fabricList, fabricCount);

    //exit; close input files; delete pointers
    furnitureIn.close();
    artIn.close();
    fabricIn.close();
    bookIn.close();

    delete [] furnitureList;
    delete [] artList;
    delete [] bookList;
    delete [] fabricList;

    return 0;
}

void printHead()
{
    cout << setw(50) << setfill('=') << " " << endl
         << setw(10) << setfill(' ') << " " << "Decoration Store Program" << endl
         << setw(50) << setfill('=') << " " << endl;
}

void writeHead(ofstream& outfile)
{
    outfile << setw(50) << setfill('=') << " " << endl
         << setw(10) << setfill(' ') << " " << "Decoration Store Program" << endl
         << setw(50) << setfill('=') << " " << endl;
}

void writeOutput(Furniture *furnitureList, int furnitureCount,
                 Art *artList, int artCount,
                 Book *bookList, int bookCount,
                 Fabric *fabricList, int fabricCount)
{
    ofstream outfile("SequencedOrders.txt");

    writeHead(outfile);


    outfile << "\tInventory is listed by category; each category is listed " << endl
            << "\tin ascending order of cost.  Items listed with the same " << endl
            << "\tprice are listed in the order in which they were processed." << endl;

    //furniture
    //art
    //book
    //fabric
    write(outfile, furnitureList, furnitureCount);
    write(outfile, artList, artCount);
    write(outfile, bookList, bookCount);
    write(outfile, fabricList, fabricCount);

    outfile.close();
}