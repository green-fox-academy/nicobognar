#include <stdio.h>

int main()
{

// Write a program that stores 3 sides of a cuboid as variables (doubles)
// You should get these variables via console input
// The program should write the surface area and volume of the cuboid like:
//
// Surface Area: 600
// Volume: 1000
    double sideX = 0;
    double sideY = 0;
    double sideZ = 0;
    printf("%s", "Please enter the length of the first side of the cuboid: \n");
    scanf("%lf", &sideX);
    printf("%s", "Please enter the length of the second side of the cuboid: \n");
    scanf("%lf", &sideY);
    printf("%s", "Please enter the length of the third side of the cuboid: \n");
    scanf("%lf", &sideZ);

    double surface_area = (sideX * 2) + (sideY * 2) + (sideZ * 2);
    double volume_cuboid = sideX * sideY * sideZ;
    printf("Surface Area: %.2lf\n", surface_area);
    printf("Volume: %.2lf\n", volume_cuboid);

    return 0;
}