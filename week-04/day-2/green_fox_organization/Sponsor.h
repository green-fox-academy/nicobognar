//
// Created by Nico on 23/04/2019.
//
#include "Person.h"
#ifndef GREEN_FOX_ORGANIZATION_SPONSOR_H
#define GREEN_FOX_ORGANIZATION_SPONSOR_H


class Sponsor : public Person {
public:
    Sponsor(std::string name, int age, Gender gender, std::string company);
    Sponsor();
    std::string _company;
    int _hiredStudents;
    void introduce() override;
    void getGoal() override;
    void hire();
    ~Sponsor();
};


#endif //GREEN_FOX_ORGANIZATION_SPONSOR_H
