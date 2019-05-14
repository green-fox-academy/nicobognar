#include<stdio.h>

int main()
{
    // Create a program that prints a few operations on two numbers: 22 and 13
    int number_one = 13;
    int number_two = 22;
    // Print the result of 13 added to 22
    int addition = number_one + number_two;
    printf("%d\n", addition);
    // Print the result of 13 substracted from 22
    int subtraction = number_one - number_two;
    printf("%d\n", subtraction);
    // Print the result of 22 multiplied by 13
    int multiplication = number_one * number_two;
    printf("%d\n", multiplication);
    // Print the result of 22 divided by 13 (as a decimal fraction)
    float division = (float)number_one / number_two;
    printf("%.2f\n", division);
    // Print the reminder of 22 divided by 13
    int modulo = number_two % number_one;
    printf("%d\n", modulo);
    // Store the results in variables and use them when you display the result

    return 0;
}