//
// Created by Nico on 24/04/2019.
//
#include <iostream>
#ifndef ANIMALS_IN_THE_ZOO_ANIMAL_H
#define ANIMALS_IN_THE_ZOO_ANIMAL_H

enum HowIsBabbyFormed {
        EGGS,
        BIRTH,
        MAYBEEGGS,
};

class Animal {
public:

protected:
    std::string _name;
    int _age;
    HowIsBabbyFormed _breedingBy;

    std::string virtual getName() = 0;
    std::string virtual breed() = 0;
};


#endif //ANIMALS_IN_THE_ZOO_ANIMAL_H
