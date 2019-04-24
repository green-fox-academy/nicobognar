//
// Created by Nico on 24/04/2019.
//

#include "bird.h"

Bird::Bird(std::string name) {
    _name = name;
    _breedingBy = HowIsBabbyFormed::EGGS;
    _age = 12;
}

Bird::Bird() {
    _name = "Default Bird Name";
    _breedingBy = HowIsBabbyFormed::EGGS;
    _age = 12;
}

Bird::~Bird() {
}

std::string Bird::getName() {
    return this->_name;
}

std::string Bird::breed() {
    switch (_breedingBy){
        case BIRTH:
            return "giving birth to younglings.";
        case EGGS:
            return "laying eggs.";
        case MAYBEEGGS:
            return "laying eggs in some cases.";
    }
}