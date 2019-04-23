//
// Created by Nico on 23/04/2019.
//
#include <iostream>
#include <vector>
#include "Mentor.h"
#include "Student.h"
#ifndef GREEN_FOX_ORGANIZATION_COHORT_H
#define GREEN_FOX_ORGANIZATION_COHORT_H


class Cohort {
public:
    Cohort(std::string name);
    std::string _cohortName;
    std::vector<Student*> students;
    std::vector<Mentor*> mentors;
    virtual void addStudent(Student* x);
    virtual void addMentor(Mentor*);
    void info();
    ~Cohort();

};


#endif //GREEN_FOX_ORGANIZATION_COHORT_H
