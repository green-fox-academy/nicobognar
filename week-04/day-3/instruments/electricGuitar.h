//
// Created by Nico on 24/04/2019.
//
#include "stringedInstrument.h"
#include <iostream>

#ifndef INSTRUMENTS_ELECTRICGUITAR_H
#define INSTRUMENTS_ELECTRICGUITAR_H


class ElectricGuitar : public StringedInstrument {
public:
    ElectricGuitar(int strings);

    ElectricGuitar();

    void play() override;

    ~ElectricGuitar();

protected:
    std::string sound() override;
};


#endif //INSTRUMENTS_ELECTRICGUITAR_H
