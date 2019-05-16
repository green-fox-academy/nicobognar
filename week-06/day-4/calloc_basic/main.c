#include <stdio.h>
#include <stdlib.h>

// with calloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits
// what's the difference between this and the previous exercise?

int main()
{
    int *array_of_ten;
    array_of_ten = (int *) calloc(10, sizeof(int)); //obviously i could replace 10 with size
    int counter = 0;
    for (int i = 0; i < 5; ++i) {
        array_of_ten[i] = i;
        ++counter;
    }
    for (int j = 0; j != counter; ++j) {
        printf("%d\n", array_of_ten[j]);
    }
    free(array_of_ten);
    array_of_ten = NULL;

    return 0;
}