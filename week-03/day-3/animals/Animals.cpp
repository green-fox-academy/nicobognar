//
// Created by Nico on 17/04/2019.
//
#include <iostream>
#include "Animals.h"

Animals::Animals(int hunger, int thirst) {
};

void Animals::eat() {
    --hunger;
}

void Animals::drink() {
    --thirst;
}

void Animals::play() {
    ++hunger;
    ++thirst;
}

Animals::~Animals() {
}
