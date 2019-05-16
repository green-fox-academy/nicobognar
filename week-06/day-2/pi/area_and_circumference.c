//
// Created by Nico on 14/05/2019.
//
#include "area_and_circumference.h"

float area_of_circle(float radius)
{
    float area = radius * radius * PI;
    return area;
}
float circumference_of_circle(float radius)
{
    float circumference = 2 * radius * PI;
    return circumference;
}