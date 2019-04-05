
#include <iostream>

int main(int argc, char *args[]) {
    double sideX = 145;
    double sideY = 60;
    double sideZ = 95;

    int surface_area = sideX * 2 + sideY * 2 + sideZ * 2;
    int volume_cuboid = sideX * sideY * sideZ;

    std::cout << "Surface Area: " << surface_area << std::endl;
    std::cout << "Volume: " << volume_cuboid << std::endl;
    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    return 0;
}