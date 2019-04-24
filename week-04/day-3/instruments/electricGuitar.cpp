//
// Created by Nico on 24/04/2019.
//

#include "electricGuitar.h"

ElectricGuitar::ElectricGuitar(int strings) {
    _numberOfStrings = strings;
    _noise = EG;
}

ElectricGuitar::ElectricGuitar() {
    _numberOfStrings = 6;
    _noise = EG;
}


std::string ElectricGuitar::sound() {
    switch (_noise) {
        case EG:
            return "Twang";
        case BG:
            return "Duum-duum-duum";
        case VIO:
            return "Screech";
    }
}

void ElectricGuitar::play() {
    std::cout << "Electric Guitar, a " << _numberOfStrings << "-stringed instrument that goes " << sound() << std::endl;
}

ElectricGuitar::~ElectricGuitar() {
}
