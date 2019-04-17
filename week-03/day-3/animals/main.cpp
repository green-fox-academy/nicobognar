#include <iostream>
#include "Animals.h"

int main() {

    Animals Puppy(50, 50);
    Animals Kitten(50, 50);
    Puppy.play();
    Kitten.drink();
    Puppy.eat();
    Puppy.drink();
    Puppy.eat();
    Puppy.eat();
    Puppy.drink();
    Puppy.eat();
    Puppy.play();
    Puppy.play();
    Puppy.play();
    Puppy.play();



    /* Create an Animal class
Every animal has a hunger value, which is a whole number
Every animal has a thirst value, which is a whole number
when creating a new animal object these values are created with the default 50 value
Every animal can eat() which decreases their hunger by one
Every animal can drink() which decreases their thirst by one
Every animal can play() which increases both by one */
    return 0;
}