#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Create a program which asks for the name of the user and strokes it
    char name[20];
    printf("Please enter your name: \n");
    scanf("%s", &name);
    printf("Your name is %d characters long.", strlen(&name));
    // Create a function which takes a string as a parameter and returns the length of it
    // Solve this exercise with and without using string.h functions


    return 0;
}