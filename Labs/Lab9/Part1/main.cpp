#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

void Initialize(int *students, int *grades, int noStudents);
void PrintArrays(int *students, int *grades, int noStudents);
int GetRandomBetween(int ceiling);
void Initialize2DArray(int table[][2], int rowSize, int colSize);
void Initialize2DArray(int **table, int rowSize, int colSize);
void Print2DArray(int table[][2], int rowSize, int colSize);
void Print2DArray(int **table, int rowSize, int colSize);
void AddStudent(int* &students, int* &grades, int& noStudents);

int main()
{
    char task = ' ';
    srand (time(NULL));

    enterTask:
    cout<<"Enter task letter (A, B, C, D): ";
    cin>>task;
    if(task =='A')
    {
        int students[50];
        int grades[50];

        Initialize(students, grades, 50);

        cout << "Initialized Arrays" << endl;
        PrintArrays(students, grades, 50);

        for (int i = 0; i < 50; i++)
        {
            students[i] = i;
            grades[i]=GetRandomBetween(100);
        }

        cout << endl << endl;
        cout << "Assigned Arrays" << endl << endl;
        PrintArrays(students, grades, 50);

    }
    else if(task == 'B')
    {
        int table[50][2];

        Initialize2DArray(table, 50, 2);
        Print2DArray(table, 50, 2);

        for (int i = 0; i < 50; i++)
        {
            table[i][0] = i;
            table[i][1] = GetRandomBetween(100);
        }

        cout << endl << endl;
        cout << "Assigned Array" << endl << endl;
        Print2DArray(table, 50, 2);

    }
    else if(task == 'C')
    {
        int numStudents = 50;
        int *students = new int[numStudents];
        int *grades = new int[numStudents];

        Initialize(students, grades, numStudents);

        cout << "Initialized Arrays" << endl;
        PrintArrays(students, grades, numStudents);

        for (int i = 0; i < numStudents; i++)
        {
            students[i] = i;
            grades[i]=GetRandomBetween(100);
        }

        cout << endl << endl;
        cout << "Assigned Arrays" << endl << endl;
        PrintArrays(students, grades, numStudents);

        cout << "Added student" << endl << endl;
        AddStudent(students, grades, numStudents);
        PrintArrays(students, grades, numStudents);

    }
    else if(task == 'D')
    {
        int **table;
        table = new int*[50];
        for (int i = 0; i < 50; i++)
        {
            table[i] = new int[2];
        }

        Initialize2DArray(table, 50, 2);
        cout << endl << endl << "Initialized Array" << endl << endl;
        Print2DArray(table, 50, 2);

        for (int i = 0; i < 50; i++)
        {
            table[i][0] = i;
            table[i][1] = GetRandomBetween(100);
        }

        cout << endl << endl;
        cout << "Assigned Array" << endl << endl;
        Print2DArray(table, 50, 2);


    }
    else
        goto enterTask;


    return 0;
}

int GetRandomBetween(int ceiling)
{
    return rand() % ceiling +1;
}

void Initialize(int *students, int *grades, int noStudents)
{
    for (int i = 0; i < noStudents; i++)
    {
        students[i] = 0;
        grades[i] = 0;
    }
}

void PrintArrays(int *students, int *grades, int noStudents)
{
    cout << setw(10) << "Students";
    cout << setw(10) << "Grades" << endl;

    for (int i = 0; i < noStudents; i++)
    {
        cout << setw(10) << students[i];
        cout << setw(10) << grades[i] << endl;
    }
}

void Initialize2DArray(int table[][2], int rowSize, int colSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            table[i][j] = 0;
        }
    }
}


void Print2DArray(int table[][2], int rowSize, int colSize)
{
    cout << setw(10) << "Students";
    cout << setw(10) << "Grades" << endl;

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            cout << setw(10) << table[i][j];
        }

        cout << endl;
    }
}

void Initialize2DArray(int **table, int rowSize, int colSize)
{
    for (int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            table[i][j] = 0;
        }
    }
}


void Print2DArray(int **table, int rowSize, int colSize)
{
    cout << setw(10) << "Students";
    cout << setw(10) << "Grades" << endl;

    for (int i = 0; i < rowSize; i++)
    {
        for (int j = 0; j < colSize; j++)
        {
            cout << setw(10) << table[i][j];
        }

        cout << endl;
    }
}

void AddStudent(int* &students, int* &grades, int& noStudents)
{
    cout << "noStudents: " << noStudents << endl;

    //copy old arrays to new arrays of length noStudents+1
    int *newStudents = new int[noStudents+1];
    int *newGrades = new int[noStudents+1];

    for (int i = 0; i < noStudents; i++)
    {
        newStudents[i] = students[i];
        newGrades[i] = grades[i];
    }


    //add new student to the end
    //noStudents already set to last index of new array
    newStudents[noStudents] = noStudents;
    newGrades[noStudents] = GetRandomBetween(100);
    
    delete [] students;
    delete [] grades;

    students = newStudents;
    grades = newGrades;
    noStudents++;
}
