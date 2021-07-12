#ifndef advisor_h_included
#define advisor_h_included

#include "studentData.h"


struct advisor{
    //advisor information goes here

    advisor();
    advisor(std::string advName);
    std::string name;
    student advisees[3];
    void meetings();
};

//function that matches students to
void matchStudentsToAdvisors(advisor* advisorList, student * studentList);

#endif /* advisor_h */
