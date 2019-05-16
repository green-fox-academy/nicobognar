#include <stdio.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/
typedef struct sandwich {
    char *name;
    float price;
    float weight;
} sandwich_t;

float whats_the_price(struct sandwich *sandwich, int amount);

int main()
{
    sandwich_t first_sandwich;
    first_sandwich.name = "puttanesca";
    first_sandwich.price = 1.50;

    sandwich_t second_sandwich;
    second_sandwich.name = "bolognese";
    second_sandwich.price = 3.50;

    int i_want_this_many_sandwiches = 0;
    printf("How many sandwiches would you like of each type?\n");
    scanf("%d", &i_want_this_many_sandwiches);
    printf("%d %s sandwiches would cost %.2f dollars.\n", i_want_this_many_sandwiches, first_sandwich.name, whats_the_price(&first_sandwich, i_want_this_many_sandwiches));
    printf("%d %s sandwiches would cost %.2f dollars.\n", i_want_this_many_sandwiches, second_sandwich.name, whats_the_price(&second_sandwich, i_want_this_many_sandwiches));

    return 0;
}

float whats_the_price(struct sandwich *sandwich, int amount)
{
    return (sandwich->price * amount);
}
