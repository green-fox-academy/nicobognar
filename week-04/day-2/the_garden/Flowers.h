//
// Created by Nico on 23/04/2019.
//
#include "PlantsInTheGarden.h"
#include <iostream>

#ifndef THE_GARDEN_FLOWERS_H
#define THE_GARDEN_FLOWERS_H


class Flowers : public PlantsInTheGarden {
public:
    Flowers(std::string color, float currentWater);
    ~Flowers();

protected:
    virtual float getRetentionRate() const;
    virtual int getWaterNeed() const;
};


#endif //THE_GARDEN_FLOWERS_H
