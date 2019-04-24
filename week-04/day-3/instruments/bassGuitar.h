//
// Created by Nico on 24/04/2019.
//
#include <iostream>
#include "stringedInstrument.h"

#ifndef INSTRUMENTS_BASSGUITAR_H
#define INSTRUMENTS_BASSGUITAR_H


class BassGuitar : public StringedInstrument {
public:
    BassGuitar(int strings);

    BassGuitar();

    void play() override;

    ~BassGuitar();

protected:
    std::string sound() override;

};


#endif //INSTRUMENTS_BASSGUITAR_H
