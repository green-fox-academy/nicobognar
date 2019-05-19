#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

void where_is_my_i(char string_array[]);

int main ()
{
    char string[55] = "This is a string for testing";
    where_is_my_i(string);

    return 0;
}

void where_is_my_i(char string_array[])
{
    for (int i = 0; i < strlen(string_array); ++i) {
        if (string_array[i] == 'i'){
            printf("There is an 'i' at position: %d \n", i);
        }
    }
}
