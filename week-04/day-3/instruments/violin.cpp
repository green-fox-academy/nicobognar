//
// Created by Nico on 24/04/2019.
//

#include "violin.h"

Violin::Violin(int strings) {
    _numberOfStrings = strings;
    _noise = VIO;
}

Violin::Violin() {
    _numberOfStrings = 4;
    _noise = VIO;
}


std::string Violin::sound() {
    switch (_noise) {
        case EG:
            return "Twang";
        case BG:
            return "Duum-duum-duum";
        case VIO:
            return "Screech";
    }
}

void Violin::play() {
    std::cout << "Violin, a " << _numberOfStrings << "-stringed instrument that goes " << sound() << std::endl;
}

Violin::~Violin() {
}


