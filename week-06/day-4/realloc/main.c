#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int x_length;
    printf("Please enter the amount of numbers you wish to enter: \n");
    scanf(" %d", &x_length);
    int *x = (int *) calloc(sizeof(int), x_length);
    printf("Please enter the numbers you wish to enter: \n");
    for (int i = 0; i < x_length; ++i) {
        scanf("%d", &x[i]);
    }
    int sum_of_x = 0;
    for (int i = 0; i < x_length; ++i) {
        sum_of_x += x[i];
    }
    int *numbers = (int *) malloc(sizeof(int) * sum_of_x);
    for (int j = 0; j < sum_of_x; ++j) {
        numbers[j] = j + 1;
    }
    for (int k = 0; k < sum_of_x; ++k) {
        printf(" %d", numbers[k]);
    }


    return 0;
}