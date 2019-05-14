#include <stdio.h>
#include <stdlib.h>
#include "area_and_circumference.h"

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

int main()
{
    float radius_input = 0;
    printf("What is the radius of your circle?\n");
    scanf("%f", &radius_input);
    printf("The area of your circle is: %.2f \n", area_of_circle(radius_input));


    return 0;
}


