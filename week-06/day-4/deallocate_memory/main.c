#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free


int main()
{
    int *array_of_ten;
    array_of_ten = (int *) malloc(10 * sizeof(int));
    int counter = 0;
    for (int i = 1; i < 21; ++i) {
        if (i % 2 == 0) {
            array_of_ten[(i / 2) - 1] = i;
            ++counter;
        }
    }
    for (int j = 0; j != counter; ++j) {
        printf("%d\n", array_of_ten[j]);
    }
    int *new = (int *) realloc(array_of_ten, 0);
    array_of_ten = NULL;
    return 0;
}