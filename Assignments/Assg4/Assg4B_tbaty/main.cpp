//standard libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>
#include <vector>

//user-defined modules
#include "Art.h"
#include "Fabric.h"
#include "Furniture.h"
#include "Book.h"

using namespace std;

//function prototypes
void printHead();
void writeOutput(vector<Furniture> vFurniture, vector<Art> vArt,
                 vector<Book> vBook, vector<Fabric> vFabric);
void writeHead(ofstream& outfile);

/* 
    changes from Assg4A_tbaty:
        [x] remove `sortAscByCost` from each module
        [x] add function template `sortAscByCost` to `DecorationStoreUtilities` 
            with same functionality
        [x] attempt to convert dynamic arrays to vectors

    this program seems like a good candidate for exploring inheritance.
    most of the structs have common elements:
        - name
        - price
        - amount in stock
 */
int main()
{
    //print header
    printHead();

    //declare variables
    vector<Furniture> furnitureList;
    vector<Art> artList;
    vector<Book> bookList;
    vector<Fabric> fabricList;

    // //read each file into a vector
    readInput(furnitureList);
    readInput(artList);
    readInput(fabricList);
    readInput(bookList);

    //print to stdout
    print(furnitureList);
    print(artList);
    print(bookList);
    print(fabricList);

    //write to file
    writeOutput(furnitureList, artList, bookList, fabricList);

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

void writeOutput(vector<Furniture> vFurniture, vector<Art> vArt,
                 vector<Book> vBook, vector<Fabric> vFabric)
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
    write(outfile, vFurniture);
    write(outfile, vArt);
    write(outfile, vBook);
    write(outfile, vFabric);

    outfile.close();
}