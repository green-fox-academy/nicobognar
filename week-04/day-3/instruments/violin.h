//
// Created by Nico on 24/04/2019.
//
#include "stringedInstrument.h"
#include <iostream>

#ifndef INSTRUMENTS_VIOLIN_H
#define INSTRUMENTS_VIOLIN_H


class Violin : public StringedInstrument {
public:
    Violin(int strings);

    Violin();

    void play() override;

    ~Violin();

protected:
    std::string sound() override;

};


#endif //INSTRUMENTS_VIOLIN_H
