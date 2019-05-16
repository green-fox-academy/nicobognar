#include <stdio.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct{
    char *address;
    float price_in_EUR;
    int number_of_rooms;
    float area_in_square_meters;
} house;

int is_it_worth_it(house valamelyik);

int how_many_are_valuable(house[], int);

int main()
{
    house house_one;
    house_one.price_in_EUR = 1460.00;
    house_one.area_in_square_meters = 300.00;
    house house_two;
    house_two.price_in_EUR = 1230.00;
    house_two.area_in_square_meters = 186.00;
    house house_three;
    house_three.price_in_EUR = 1460.00;
    house_three.area_in_square_meters = 231.00;
    house array_of_houses[3];
    array_of_houses[0] = house_one;
    array_of_houses[1] = house_two;
    array_of_houses[2] = house_three;


    return 0;
}
counter segg
    for (int i = 0; i < meretparameter; ++i) {

        segg += isitworthitfuggveny(parameter[i])
    } return segg
