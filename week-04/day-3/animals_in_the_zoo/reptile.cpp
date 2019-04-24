//
// Created by Nico on 24/04/2019.
//

#include "reptile.h"

Reptile::Reptile(std::string name) {
    _name = name;
    _breedingBy = HowIsBabbyFormed::MAYBEEGGS;
    _age = 1;
}

Reptile::Reptile() {
    _name = "Default Reptile Name";
    _breedingBy = HowIsBabbyFormed::MAYBEEGGS;
    _age = 1645;
}

Reptile::~Reptile() {
}

std::string Reptile::getName() {
    return this->_name;
}

std::string Reptile::breed() {
    switch (_breedingBy){
        case BIRTH:
            return "giving birth to younglings.";
        case EGGS:
            return "laying eggs.";
        case MAYBEEGGS:
            return "laying eggs in some cases.";
    }
}