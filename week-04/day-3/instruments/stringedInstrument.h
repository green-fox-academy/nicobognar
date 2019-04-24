//
// Created by Nico on 24/04/2019.
//
#include "instrument.h"

#ifndef INSTRUMENTS_STRINGEDINSTRUMENT_H
#define INSTRUMENTS_STRINGEDINSTRUMENT_H


class StringedInstrument : public Instrument {
public:
    StringedInstrument();

protected:

    int _numberOfStrings;

    std::string virtual sound() = 0;

};


#endif //INSTRUMENTS_STRINGEDINSTRUMENT_H
