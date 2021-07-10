#include"studentData.h"
#include "advisor.h"

int main()
{
    student * studentList;
    advisor *advisorList;
    advisorList = new advisor[3];
    advisorList[0].name = "Ben";
    advisorList[1].name = "Jerry";
    advisorList[2].name = "Tom";
    int numberOfStudents=0;
    studentList=readDataFromFile(studentList, numberOfStudents);
    sortStudentData(studentList, numberOfStudents);
    matchStudentsToAdvisors(advisorList, studentList);
	printDataToFile(studentList, numberOfStudents);
	for (int i = 0; i < 3; i++)
        advisorList[i].meetings();
    return 0;
}
