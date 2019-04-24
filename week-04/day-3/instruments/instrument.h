//
// Created by Nico on 24/04/2019.
//
#include <iostream>

#ifndef INSTRUMENTS_INSTRUMENT_H
#define INSTRUMENTS_INSTRUMENT_H

enum Noise {
    EG,
    BG,
    VIO
};

class Instrument {
public:
    void virtual play() = 0;

protected:
    std::string _name;
    Noise _noise;
};


#endif //INSTRUMENTS_INSTRUMENT_H
