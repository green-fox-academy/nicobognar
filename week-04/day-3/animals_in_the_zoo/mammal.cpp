//
// Created by Nico on 24/04/2019.
//

#include "mammal.h"

Mammal::Mammal(std::string name) {
    _name = name;
    _breedingBy = HowIsBabbyFormed::BIRTH;
    _age = 1;
}

Mammal::Mammal() {
    _name = "Default Mammal Name";
    _breedingBy = HowIsBabbyFormed::BIRTH;
    _age = 15;
}

Mammal::~Mammal() {
}

std::string Mammal::getName() {
    return this->_name;
}

std::string Mammal::breed() {
    switch (_breedingBy){
        case BIRTH:
            return "giving birth to younglings.";
        case EGGS:
            return "laying eggs.";
        case MAYBEEGGS:
            return "laying eggs in some cases.";
    }
}

