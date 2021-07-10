#include"studentData.h"

int main()
{
    student * studentList;
    int numberOfStudents=0;
    studentList=readDataFromFile(studentList, numberOfStudents);
    sortStudentData(studentList, numberOfStudents);
	printDataToFile(studentList, numberOfStudents);
   ///students should complete it
    return 0;
}
