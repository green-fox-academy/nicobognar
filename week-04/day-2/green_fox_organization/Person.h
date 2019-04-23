//
// Created by Nico on 23/04/2019.
//
#include <iostream>

#ifndef GREEN_FOX_ORGANIZATION_PERSON_H
#define GREEN_FOX_ORGANIZATION_PERSON_H

enum Gender{
    MALE,
    FEMALE
};

class Person {
public:
    Person(std::string name, int age, Gender gender);
    Person();
    std::string _name;
    int _age;
    Gender _gender;
    virtual void introduce();
    virtual void getGoal();
    std::string genderAsString();
    ~Person();
};


#endif //GREEN_FOX_ORGANIZATION_PERSON_H
