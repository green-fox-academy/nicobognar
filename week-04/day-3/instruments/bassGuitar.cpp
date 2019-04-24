//
// Created by Nico on 24/04/2019.
//

#include "bassGuitar.h"

BassGuitar::BassGuitar(int strings) {
    _numberOfStrings = strings;
    _noise = BG;
}

BassGuitar::BassGuitar() {
    _numberOfStrings = 4;
    _noise = BG;
}


std::string BassGuitar::sound() {
    switch (_noise) {
        case EG:
            return "Twang";
        case BG:
            return "Duum-duum-duum";
        case VIO:
            return "Screech";
    }
}

void BassGuitar::play() {
    std::cout << "Bass Guitar, a " << _numberOfStrings << "-stringed instrument that goes " << sound() << std::endl;
}

BassGuitar::~BassGuitar() {
}
