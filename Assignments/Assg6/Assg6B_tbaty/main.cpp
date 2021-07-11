#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

#include "employee.h"

using namespace std;

void readInput(vector<Employee>& v, ifstream& inFile);
void calculateBonuses(vector<Employee>& v);
void printReport(vector<Employee> v);

//Compute total sales for each employee; generate sales report
int main()
{
    //Read data.txt
    //open input file
    ifstream inFile("data.txt");
    if (!inFile)
    {
        cerr << "Error: file \'data.txt\' not found" << endl;
        return -1;
    }

    //read data into Employee array
    vector<Employee> vEmp;

    readInput(vEmp, inFile);
    #ifdef DEBUG
    cerr << "debug: list populated" << endl;
    cerr << "first ten elements of list" << endl;
    for (int i = 0; i < 10; i++)
        vEmp[i].printMember(cerr);
    cerr << endl;
    cerr << "last ten elements of list" << endl;
    for (int i = vEmp.size() - 10; i < vEmp.size(); i++)
        vEmp[i].printMember(cerr);
    cerr << endl;
    #endif

    //sort list in descending order by totalSales
    sortDescByTotalSales(vEmp);
    #ifdef DEBUG
    cerr << "debug: sorted list in descending order by totalSales" << endl;
    cerr << "debug: first element of list: ";
    vEmp.front().printMember(cerr);
    cerr << "debug: last element of list: ";
    vEmp.back().printMember(cerr);
    cerr << endl;
    #endif


    //calculate bonus
    calculateBonuses(vEmp);
    #ifdef DEBUG
    cerr << "debug: employee bonuses calculated" << endl
         << "debug: first element of list: ";
         vEmp[0].printMember(cerr);
         cerr << endl;
    #endif

    //Print data to results.txt
    //print sorted list
    printAll(vEmp);

    //call printReport()
    printReport(vEmp);

    inFile.close();
    return 0;
}

void readInput(vector<Employee>& v, ifstream& inFile)
{
    //gather info
    int empID;
    char comma;
    char firstName[17], lastName[17];//c-strings for use with get function; length = max name length + \0
    int storeID;
    double salary;
    int totalDaysWorked;
    double totalSales;

    string line = "";
    getline(inFile, line);

    while (!inFile.eof())
    {
        istringstream lineIn(line);
        totalSales = 0.0;//reset for each record
        
        lineIn >> empID >> comma >> ws;
        lineIn.get(firstName, 17, ',');
        lineIn >> comma >> ws;
        lineIn.get(lastName, 17, ',');
        lineIn >> comma >> storeID >> comma 
               >> salary >> comma >> totalDaysWorked >> comma;

        double sale = 0.0;
        lineIn >> sale;
        while (lineIn)
        {
            totalSales += sale;
            lineIn >> sale;
        }

        //using string constructor for implicit conversion from c-string to string
        v.push_back(Employee(empID, string(firstName), string(lastName), storeID, 
                    salary, totalDaysWorked, totalSales));

        getline(inFile, line);
    }
}

void calculateBonuses(vector<Employee>& v)
{
    //for each Employee
        //calculate bonus (member function?)
    
    // (0.001 * salary) * (0.001 * (totalSales - minCoSales))
    // lowest performer does not receive a bonus since 
    // totalSales - minCoSales = 0 by definition
    double minCoSales = v.back()._totalSales;
    #ifdef DEBUG
    cerr << "debug: minimum company-wide sales identified: " << minCoSales << endl;
    #endif
    for (Employee& e : v)
    {
        e.calculateBonus(minCoSales);
    }
}

void printReport(vector<Employee> v)
{

    //append to existing file "results.txt"
    ofstream outFile("results.txt", iostream::app);
    if (!outFile)
    {
        cerr << "Error: unable to create/open output file" << endl;
        return;
    }

    outFile << fixed << setprecision(2);

    //append top ten sales in prescribed format
    outFile << left << setw(23) << "Top Ten Highest Sales" << " " 
            << left << setw(7) << "empID" << " " 
            << left << setw(11) << "totalSales" << endl;
    for (int i = 0; i < 10; i++)
    {
        outFile << left << setw(23) << " " << " " 
                << left << setw(8) << v[i]._empID
                << left << setw(11) << v[i]._totalSales << endl;
    }

    //append lowest ten sales in prescribed format
    outFile << left << setw(23) << "Bottom Ten Lowest Sales" << " " 
            << left << setw(7) << "empID" << " " 
            << left << setw(11) << "totalSales" << endl;
    for (int i = v.size() - 10; i < v.size(); i++)
    {
        outFile << left << setw(23) << " " << " " 
                << left << setw(8) << v[i]._empID
                << left << setw(11) << v[i]._totalSales << endl;
    }

    //append Average sales across company 
    //append Total Sales overall 
    //append Total Bonuses Overall 
    double avgCoSales, totalCoSales, totalCoBonuses;
    avgCoSales = totalCoSales = totalCoBonuses = 0.0;

    for (Employee e : v)
    {
        totalCoSales += e._totalSales;
        totalCoBonuses += e._bonus;
    }
    avgCoSales = totalCoSales / v.size();

    outFile << "Avg Sales Across the Company: " << avgCoSales << endl
            << "Total Sales Overall: " << totalCoSales << endl
            << "Total Bonuses Overall: " << totalCoBonuses << endl;
    
    outFile.close();

}