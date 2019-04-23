//
// Created by Nico on 23/04/2019.
//

#include "Mentor.h"


Mentor::Mentor(std::string name, int age, Gender gender, Level level) {
    _name = name;
    _age = age;
    _gender = gender;
    _level = level;
}
Mentor::Mentor() {
    _name = "Jane Doe";
    _age = 30;
    _gender = Gender::FEMALE;
    _level = Level::INTERMEDIATE;
}

void Mentor::introduce() {
    std::cout << "Hi, I'm " << _name << ", a " << _age << " year old " << genderAsString() << " " << levelAsString() << " mentor." << std::endl;
}

void Mentor::getGoal() {
    std::cout << "My goal is: Educate brilliant junios software developers." << std::endl;
}

std::string Mentor::levelAsString() {
    switch (_level) {
        case INTERMEDIATE:
            return "intermediate";
        case JUNIOR:
            return "junior";
        case SENIOR:
            return "senior";
    }
}

Mentor::~Mentor() {

}


