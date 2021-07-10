#include <iostream>
#include <fstream>
#include "Analyzer.h"

int main()
{

    cout << "Analyzer 2" << endl;
    Analyzer a2;
    a2.SetTotalSize(300);
    a2.CountStats();
    a2.PrintStats();

    return 0;
}
