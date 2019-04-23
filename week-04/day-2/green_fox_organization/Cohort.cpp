//
// Created by Nico on 23/04/2019.
//

#include "Cohort.h"

Cohort::Cohort(std::string name) {
    _cohortName = name;
    mentors;
    students;
}

void Cohort::addStudent(Student* x) {
    students.push_back(x);
}

void Cohort::addMentor(Mentor* x) {
    mentors.push_back(x);
}

void Cohort::info() {
    std::cout << "The " << _cohortName << " cohort has " << students.size() << " students, and " << mentors.size() << " mentors." << std::endl;
}

Cohort::~Cohort() {

}
