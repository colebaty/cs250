#include "advisor.h"
#include <fstream>
#include <iomanip>

using namespace std;

advisor::advisor()
{
    name = "";
}

advisor::advisor(std::string advName)
{
    name = advName;
}

void matchStudentsToAdvisors(advisor* advisorList, student* studentList)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            advisorList[i].advisees[j] = studentList[j + (3*i)];
    }
}

void advisor::meetings()
{
    ofstream out("studentResults.txt", fstream::app);

    out << setw(20) << setfill('=') << " " << endl;

    for (int i = 0; i < 3; i++)
    {
        if (advisees[i].currentGrade() > 'C')
        {
            out << name << " needs to meet with " << advisees[i].studentName
                << " ID: " << advisees[i].studentID << endl;
        }
    }

    out.close();
}
