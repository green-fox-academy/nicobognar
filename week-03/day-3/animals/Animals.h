//
// Created by Nico on 17/04/2019.
//
#include <iostream>

#ifndef ANIMALS_ANIMALS_H
#define ANIMALS_ANIMALS_H


class Animals {
public:
    Animals(int hunger, int thirst);

    void eat();

    void drink();

    void play();

    ~Animals();

private:
    int hunger = 50;
    int thirst = 50;
};


#endif //ANIMALS_ANIMALS_H
