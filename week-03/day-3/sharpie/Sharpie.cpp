//
// Created by Nico on 17/04/2019.
//
#include <iostream>

#include "Sharpie.h"

Sharpie::Sharpie(std::string color, float width) {
    setColor(color);
    setWidth(width);
}

void Sharpie::setColor(std::string newColor) {
    Sharpie::color = newColor;
}

void Sharpie::setWidth(float sWidth) {
    Sharpie::width = sWidth;
}

void Sharpie::use() {
    --inkAmount;
}

Sharpie::~Sharpie() {

}

