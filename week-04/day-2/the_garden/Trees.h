//
// Created by Nico on 23/04/2019.
//
#include <iostream>
#include "PlantsInTheGarden.h"

#ifndef THE_GARDEN_TREES_H
#define THE_GARDEN_TREES_H


class Trees : public PlantsInTheGarden {
    Trees(std::string color, float currentWater);

    ~Trees();

};


#endif //THE_GARDEN_TREES_H
