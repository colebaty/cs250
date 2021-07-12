#include <iostream>
#include <cmath>
#include "arrayUtils.h"

using namespace std;

const int MAX_ARR_SIZE = 10000;

// Determine if a data set is skewed
// reads input from command line, ignoring whitespace, until manually given EOF (^D)
void skew ()
{
//* Read in the Data using cin
    double dataArray[MAX_ARR_SIZE];

    int index;
    while (cin)
    {
        cin >> dataArray[index];
        index++;
    }
    int nData = index - 1;

    //* Compute Skew
    //** Compute the mean
    double mean, sum;
    
    for (int i = 0; i < nData; i++)
    {
        //*** Compute the sum of all data values
        sum += dataArray[i];
    }

    //*** Divide the sum by the number of data values to compute the mean
    mean = sum / (double)nData;

    //** Compute the median
    //*** Sort the data values
    insertionSort(dataArray, nData);

    //*** select the middle value
    double median;
    if (nData % 2 == 1)
        median = dataArray[nData / 2];
    else
        median = (dataArray[nData / 2] + dataArray[nData / 2 - 1]) / 2.0;
    
    //**** if the number of data values is odd, selet the middle value


//** Compute the std_dev
//*** Use the mean value computed earlier and the sum of squares to compute the std_dev
    double sumsquares = 0.0;
    for (int i = 0; i < nData; i ++)
    {
        sumsquares += dataArray[i] * dataArray[i];
    }
    double std_dev = sqrt((sumsquares - nData * mean*mean)/(double)(nData - 1));
    
    //** Use mean, median, and std_dev to compute the skew
    double skew;
    skew = 3.0 * (mean - median) / std_dev; 
    
    //* Print whether data is badly skewed
    //** if skew < -1.0 || skew > 1, then it is badly skewed
    if (skew < -1.0 || skew > 1)
        cout << "Badly skewed\n";
    //** else it is not badly skewed.
    else
        cout << "Not badly skewed\n";

}


int main()
{
  skew();
  return 0;
}

