//
// Created by Nico on 23/04/2019.
//

#include "Flowers.h"

Flowers::Flowers(std::string color, float currentWater)
        : PlantsInTheGarden(color, FLOWER, currentWater) {
}

Flowers::~Flowers() {

}

int Flowers::getWaterNeed() const {
    return 5;
}

float Flowers::getRetentionRate() const {
    return 0.75;
}
