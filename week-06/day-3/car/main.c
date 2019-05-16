#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

typedef enum car_type {
    VOLVO,
    TOYOTA,
    LAND_ROVER,
    TESLA
} type_t;

char* get_type_name(type_t type)
{
    switch (type)
    {
        case VOLVO: return "Volvo";
        case TOYOTA: return "Toyota";
        case LAND_ROVER: return "Land Rover";
        case TESLA: return "Tesla";
    }
}

struct car {
    type_t type;
    double km;
    double gas;
};

void whats_this_car_all_about(struct car *the_car);

int main()
{
    struct car my_volvo;
    my_volvo.type = VOLVO;
    my_volvo.km = 1350.23;
    my_volvo.gas = 12.32;

    struct car my_tesla;
    my_tesla.type = TESLA;
    my_tesla.km = 0.69;

    whats_this_car_all_about(&my_volvo);
    whats_this_car_all_about(&my_tesla);

    return 0;
}

void whats_this_car_all_about(struct car *the_car)
{
    if (the_car->type != TESLA){
        printf("This car is a %s brand car that has already been driven %.2lf kilometers, and has %.2lf litres of gas in it.\n", get_type_name(the_car->type), the_car->km, the_car->gas);
    }
    else
        printf("This car is a %s brand car that has already been driven %.2lf kilometers.\n", get_type_name(the_car->type), the_car->km);

}