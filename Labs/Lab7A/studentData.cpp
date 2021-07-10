#include "studentData.h"
#include<iostream>
#include<fstream>
#include <iomanip>

using namespace std;

///implement memebr functions and stand alone functions

int student::studentAverage()
{
    return (course1 + course2 + course3) / 3;
}

bool student::checkIfGreater(int otherStudentAverage)
{
    return studentAverage() > otherStudentAverage;
}


student* readDataFromFile(student * studentData, int & numberOfStudents )
{
    ifstream inFile;
    int i=0;
    numberOfStudents=0;
    inFile.open("studentData.txt");
    if(!inFile)
        cout<<endl<<"Cannot open the file";
    inFile>>numberOfStudents;
    studentData=new student[numberOfStudents];
    while(!inFile.eof())
    {
        inFile>>studentData[i].studentName;
        inFile>>studentData[i].studentID;
        inFile>>studentData[i].course1;
        inFile>>studentData[i].course2;
        inFile>>studentData[i].course3;
        i++;
    }

    return studentData;
}

void printDataToFile(student * studentList, int numberOfStudents)
{
    cout << "generating output in text file" << endl << endl;
    ofstream outFile;
    outFile.open("studentResults.txt");
    for( int i=0;i<numberOfStudents;i++)
    {
        outFile << left <<setw(12) << setfill(' ')<<studentList[i].studentName
        << left <<setw(12) << setfill(' ')<<studentList[i].studentID
        << left <<setw(6) << setfill(' ')<<studentList[i].course1
        << left <<setw(6) << setfill(' ')<<studentList[i].course2
        << left <<setw(6) << setfill(' ')<<studentList[i].course3
        << left <<setw(6) << setfill(' ')<<studentList[i].studentAverage()<<endl;
    }
    outFile.close();
}

void sortStudentData(student *studentList, int numberOfStudents)
{
    student temp;

    for (int i = 0; i < numberOfStudents; i++)
    {
        for (int j = i+1; j < numberOfStudents; j++)
        {
            if (studentList[i].studentID < studentList[j].studentID)
            {
                temp = studentList[i];
                studentList[i] = studentList[j];
                studentList[j] = temp;
            }
        }
    }
}
