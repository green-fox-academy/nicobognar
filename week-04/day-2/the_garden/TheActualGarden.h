//
// Created by Nico on 23/04/2019.
//
#include <vector>
#include <iostream>
#include "PlantsInTheGarden.h"
#include "Trees.h"
#include "Flowers.h"

#ifndef THE_GARDEN_THEACTUALGARDEN_H
#define THE_GARDEN_THEACTUALGARDEN_H


class TheActualGarden {
public:
    std::vector<Trees*, Flowers*> theGarden;

    int howManyNeedWater(std::vector<Trees*, Flowers*> lookAtThis);
    void waterThePlants(std::vector<Trees*, Flowers*> targetGarden, int amountOfWater);
};


#endif //THE_GARDEN_THEACTUALGARDEN_H
