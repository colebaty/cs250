#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

int main()
{
    int numPasswords = 0;
    int randNum = 0;
    int originalLength = 0;
    int month = 0;
    int day = 0;
    char trash = ' ';
    char firstLetter = ' ';
    string inputInt = "";
    string inputString = "";
    string allInput = "";
    string tmpInput = "";
    string password = "";
    string lastName = "";

    cout << "Please enter your last name" << endl;
    cin >> lastName;
    cout << "Please enter the month and day i.e.(1/25)" << endl;
    cin >> month >> trash >> day;

    firstLetter = lastName[0];

    if((firstLetter > 64 && firstLetter < 78) || (firstLetter > 96 && firstLetter < 110))
    {
        if(day > 14 && day < 21)
            cout << "Date Verified" << endl;
        else
        {
            cout << "Error: Names that begin with A-M register between the 15th and the 20th!" << endl;
            return 1;
        }
    }
    else if((firstLetter > 77 && firstLetter < 91) || (firstLetter > 108 && firstLetter < 123))
    {
        if(day > 19 && day < 26)
            cout << "Date Verified" << endl;
        else
        {
            cout << "Error: Names that begin with N-Z register between the 20th and the 25th!" << endl;
            return 1;
        }
    }
    else
    {
        cout << "Invalid last name!" << endl;
        return 1;
    }

    cout << "Please enter a multi-digit integer" << endl;
    cin >> inputInt;
    cout << "Please enter a string" << endl;
    cin >> inputString;
    cout << "How many passwords would you like to generate?" << endl;
    cin >> numPasswords;
    cout << "\n\n";


    allInput = inputInt + inputString;
    tmpInput = inputInt + inputString;

    srand (time(NULL));
    for(int i = 0; i < numPasswords; i++)
    {
        originalLength = tmpInput.length();
        for (int j = 0; j < originalLength; j++)
        {
            randNum = rand() % tmpInput.length();
            password += tmpInput[randNum];
            tmpInput.erase (tmpInput.begin()+randNum);
        }
        cout << "Password " << i << ":\t" << password << endl;
        password = "";
        tmpInput = allInput;
    }

    return 0;
}
