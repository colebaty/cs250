
#ifndef studentData_h_included
#define studentData_h_included
#include <iostream>

struct  student
{
    std::string studentName;
    int studentID;
    int course1;
    int course2;
    int course3;
    int studentAverage();
    bool checkIfGreater(int otherStudentAverage);

  ///add member functions here
};

///add stand alone functions here
///sorting function
student * readDataFromFile(student * studentList, int & numberOfStudents);
void printDataToFile(student * studentList, int numberOfStudents);
void sortStudentData(student *studentList, int numberOfStudents);


#endif /* studentData_h */
