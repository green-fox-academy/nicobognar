#include <iostream>
#include "Sharpie.h"

int main() {

    Sharpie firstSharpie("green", 4.71);
    Sharpie secondSharpie("red", 3.45);
    secondSharpie.use();
    firstSharpie.use();

    return 0;
}