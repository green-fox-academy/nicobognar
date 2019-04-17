//
// Created by Nico on 17/04/2019.
//
#include <iostream>

#ifndef SHARPIE_SHARPIE_H
#define SHARPIE_SHARPIE_H


class Sharpie {

public:
    Sharpie(std::string color, float width);

    void setColor(std::string newColor);

    void setWidth(float width);

    void use();

    ~Sharpie();

private:
    std::string color = "blank";
    float width = 0;
    float inkAmount = 100;

};


#endif //SHARPIE_SHARPIE_H
