//
// Created by Nico on 23/04/2019.
//
#include <iostream>
#include "Person.h"

Person::Person(std::string name, int age, Gender gender){
    _name = name;
    _age = age;
    _gender = gender;
}


Person::Person() {
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::FEMALE;
}

void Person::introduce() {
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << genderAsString() << "." << std::endl;
}

std::string Person::genderAsString() {
    switch (_gender) {
        case FEMALE:
            return "female";
        case MALE:
            return "male";
    }
}

void Person::getGoal() {
    std::cout << "My goal is: Live for the moment!" << std::endl;
}

Person::~Person() {

}
