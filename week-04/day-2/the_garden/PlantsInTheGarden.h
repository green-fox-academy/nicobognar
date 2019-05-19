//
// Created by Nico on 23/04/2019.
//
#include <iostream>

#ifndef THE_GARDEN_PLANTSINTHEGARDEN_H
#define THE_GARDEN_PLANTSINTHEGARDEN_H

enum plantType {
    FLOWER,
    TREE
};

class PlantsInTheGarden {
public:
    PlantsInTheGarden(std::string color, plantType whatIsIt, float currentWater);
    ~PlantsInTheGarden();

    bool needsWater() const;

protected:
    virtual float getRetentionRate() const;
    virtual int getWaterNeed() const;

private:
    std::string _color;
    plantType _whatIsIt;
    float _currentWater;

    std::string plantAsAString();

};


#endif //THE_GARDEN_PLANTSINTHEGARDEN_H
