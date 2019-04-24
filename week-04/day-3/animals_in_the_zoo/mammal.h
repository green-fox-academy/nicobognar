//
// Created by Nico on 24/04/2019.
//
#ifndef ANIMALS_IN_THE_ZOO_MAMMAL_H
#define ANIMALS_IN_THE_ZOO_MAMMAL_H

#include <iostream>
#include "animal.h"


class Mammal : public Animal {
public:
    Mammal(std::string name);

    Mammal();

    ~Mammal();

    std::string getName() override;

    std::string breed() override;

};


#endif //ANIMALS_IN_THE_ZOO_MAMMAL_H
