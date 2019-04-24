//
// Created by Nico on 24/04/2019.
//
#include "animal.h"
#include <iostream>
#ifndef ANIMALS_IN_THE_ZOO_BIRD_H
#define ANIMALS_IN_THE_ZOO_BIRD_H


class Bird : public Animal {
public:
    Bird(std::string name);

    Bird();

    ~Bird();

    std::string getName() override;

    std::string breed() override;

};


#endif //ANIMALS_IN_THE_ZOO_BIRD_H
