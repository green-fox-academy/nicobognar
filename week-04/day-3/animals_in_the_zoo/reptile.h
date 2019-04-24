//
// Created by Nico on 24/04/2019.
//
#include "animal.h"
#include <iostream>
#ifndef ANIMALS_IN_THE_ZOO_REPTILE_H
#define ANIMALS_IN_THE_ZOO_REPTILE_H


class Reptile : public Animal {
public:
    Reptile(std::string name);

    Reptile();

    ~Reptile();

    std::string getName() override;

    std::string breed() override;

};


#endif //ANIMALS_IN_THE_ZOO_REPTILE_H
