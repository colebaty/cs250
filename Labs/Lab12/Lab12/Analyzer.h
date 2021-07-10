#ifndef ANALYZER_H
#define ANALYZER_H
#include <iostream>
using namespace std;

class Analyzer
{
    
    public:
        Analyzer();
        ~Analyzer();
        Analyzer(int *p, int *r, int sizeP, int sizeR, int totalS);
        int GetTP(){return _tp;}
        int GetTN(){return _tn;}
        int GetFP(){return _fp;}
        int GetFN(){return _fn;}
        int GetTotalSize(){return _totalSize;}
        void SetTP(int tp){_tp = tp;}
        void SetTN(int tn){_tn = tn;}
        void SetFP(int fp){_fp = fp;}
        void SetFN(int fn){_fn = fn;}
        void SetTotalSize(int size){_totalSize = size;}
        void PrintStats();
        void PrintObject();
        void CountStats();

    private:
		int _tp;
        int _fp;
        int _fn;
        int _tn;
		int *relevant;
        int *predicted;
		int _sizeP;
        int _sizeR;
        int _totalSize;

        void ReadPredicted();
        void ReadRelevant();
};

#endif // ANALYZER_H
