//
// Created by Nico on 23/04/2019.
//

#include "PlantsInTheGarden.h"

PlantsInTheGarden::PlantsInTheGarden(std::string color, plantType whatIsIt, float currentWater) :
        _color(color), _whatIsIt(whatIsIt), _currentWater(currentWater) {

}

std::string PlantsInTheGarden::plantAsAString() {
    switch (_whatIsIt){
        case FLOWER:
            return "flower";
        case TREE:
            return "tree";

    }
}

PlantsInTheGarden::~PlantsInTheGarden() {

}

float PlantsInTheGarden::getRetentionRate() const {
    return 0;
}

int PlantsInTheGarden::getWaterNeed() const {
    return 0;
}

bool PlantsInTheGarden::needsWater() const {
    return _currentWater < getWaterNeed();
}
