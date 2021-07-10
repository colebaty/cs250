#include <fstream>
#include "Analyzer.h"

Analyzer::~Analyzer()
{
    
    delete relevant;
    delete predicted;
}

void Analyzer::PrintStats()
{
    cout<<"True Positives:"<<_tp<<endl;
    cout<<"False Positives:"<<_fp<<endl;
    cout<<"True Negatives:"<<_tn<<endl;
    cout<<"False Negatives:"<<_fn<<endl;
}

Analyzer::Analyzer(int *p, int *r, int sizeP, int sizeR, int totalS)
{
   
    _tp = 0;
    _fp = 0;
    _fn = 0;
    _tn = 0;
    
    //deep copy for pointers
    relevant = new int[sizeR];
    predicted = new int[sizeP];

    for (int i = 0; i < sizeR; i++)
    {
        relevant[i] = r[i];
    }
    for (int i = 0; i < sizeP; i++)
    {
        predicted[i] = r[i];
    }

    _sizeP = sizeP;
    _sizeR = sizeR;
    _totalSize = totalS;
}

Analyzer::Analyzer()
{
    _tp = 0;
    _fp = 0;
    _fn = 0;
    _tn = 0;
    //relevant = NULL;
    //predicted = NULL;
    _sizeP = 0;
    _sizeR = 0;
    _totalSize = 0;

    ReadPredicted();
    ReadRelevant();

}

void Analyzer::PrintObject()
{
    cout<<"TP:"<<_tp<<endl;
    cout<<"FP:"<<_fp<<endl;
    cout<<"printing array 0"<<endl;
    cout<<"relevant[0]:"<<relevant<<endl;
    cout<<"predicted[0]:"<<predicted<<endl;
}

void Analyzer::CountStats()
{
    int tempID;
    for(int i=0; i<_sizeR; i++)
    {
        tempID = relevant[i];
        for(int j=0; j<_sizeP; j++)
        {
            if(predicted[j]==tempID)
            {
                _tp++;
                break;
            }
        }
    }
    cout<<"Predicted Correctly/True Positives:"<<_tp<<endl;
    SetFN(_sizeR - _tp);
    SetFP(_sizeP - _tp);
    SetTN(_totalSize - _fp);
}

void Analyzer::ReadPredicted()
{
    //read in 2nd file
    ifstream myfile;
    myfile.open("predicted.txt");
    myfile>>_sizeP;
    predicted = new int[_sizeP];
    
    for(int i=0; i<_sizeP; i++)
        myfile>>predicted[i];

    myfile.close();
}

void Analyzer::ReadRelevant()
{
    ifstream myfile;
    myfile.open("relevant.txt");
    myfile>>_sizeR;
    relevant = new int[_sizeR];

    for(int i=0; i<_sizeR; i++)
        myfile>>relevant[i];

    myfile.close();

}
