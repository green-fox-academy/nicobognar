#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
    int *first_array;
    first_array = (int *) malloc(sizeof(int) * 10);
    int counter_for_first = 0;
    for (int i = 1; i < 21; ++i) {
        if (i % 2 == 0) {
            first_array[(i / 2) - 1] = i;
            ++counter_for_first;
        }
    }
    for (int j = 0; j != counter_for_first; ++j) {
        printf("%d\n", first_array[j]);
    }

    int *second_array;
    second_array = (int *) malloc(sizeof(int) * 10);
    int counter_for_second = 0;
    for (int i = 1; i < 21; ++i) {
        if (i % 2 == 1) {
            second_array[((i + 1) / 2) - 1] = i;
            ++counter_for_second;
        }
    }
    for (int j = 0; j != counter_for_second; ++j) {
        printf("%d\n", second_array[j]);
    }
    first_array = (int *) realloc(first_array, sizeof(int) * (counter_for_first + counter_for_second));
    for (int k = 0; k < counter_for_second; ++k) {
        first_array[counter_for_first+k] = second_array[k];

    }
    for (int l = ((counter_for_first + counter_for_second) - 1); l >= 0 ; --l) {
        printf("%d \n", first_array[l]);
    }

    free(first_array);
    first_array = NULL;
    free(second_array);
    second_array = NULL;
    return 0;
}