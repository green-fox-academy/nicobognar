#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length_of_name(char *name);
int length_of_name_two(char *name);

int main()
{
    // Create a program which asks for the name of the user and strokes it
    char name[20];
    printf("Please enter your name: \n");
    scanf("%s", name);
    printf("Your name is %d characters long.\n", strlen(name));
    printf("%d\n", length_of_name(name));
    printf("%d", length_of_name_two(name));
    // Solve this exercise with and without using string.h functions


    return 0;
}

int length_of_name(char *name)
{
    return strlen(name);
}

int length_of_name_two(char *name)
{
    int value_of_length = 0;
    for (;  *name != '\0'; name++) {
        value_of_length++;
    }
    return value_of_length;
}
