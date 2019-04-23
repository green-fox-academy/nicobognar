//
// Created by Nico on 23/04/2019.
//
#include "Person.h"
#ifndef GREEN_FOX_ORGANIZATION_STUDENT_H
#define GREEN_FOX_ORGANIZATION_STUDENT_H


class Student : public Person {
public:
    Student(std::string name, int age, Gender,std::string previousOrganization);
    Student();
    std::string _previousOrganization;
    int _skippedDays;
    void getGoal() override;
    void introduce() override;
    void skipDays(int numberOfDays);
    ~Student();
};


#endif //GREEN_FOX_ORGANIZATION_STUDENT_H
