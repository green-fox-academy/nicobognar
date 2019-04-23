//
// Created by Nico on 23/04/2019.
//
#include "Person.h"
#include <iostream>
#ifndef GREEN_FOX_ORGANIZATION_MENTOR_H
#define GREEN_FOX_ORGANIZATION_MENTOR_H

enum Level{
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};

class Mentor : public Person {
public:
    Mentor(std::string name, int age, Gender gender, Level level);
    Mentor();
    Level _level;
    void introduce() override;
    void getGoal() override;
    std::string levelAsString();
    ~Mentor();
};


#endif //GREEN_FOX_ORGANIZATION_MENTOR_H
