#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int are_they_the_same(char *first, char *second);

int main()
{
    // Create a program which asks for two strings and stores them
    char string_one[30];
    char string_two[30];
    printf("Please enter a word of your choosing: \n");
    scanf("%s", string_one);
    printf("Please enter a word of your choosing: \n");
    scanf("%s", string_two);
    printf("%s", are_they_the_same(string_one, string_two) ? "They are the same." : "They are not the same.");
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    return 0;
}
int are_they_the_same(char *first, char *second)
{
    if (strlen(first) != strlen(second))
        return 0;
    int steps_for_first = 0;
    for (; *first != '\0'; ++first, ++steps_for_first) {
        if (*first < 91 && *first > 64)
            *first += 32;
    }
    for (; steps_for_first != 0 ; --steps_for_first) {
        --*first;
    }
    int steps_for_second = 0;
    for (; *second != '\0'; ++second, ++steps_for_second) {
        if (*second < 91 && *second > 64)
            *second += 32;
    }for (; steps_for_second != 0 ; --steps_for_second) {
        --*second;
    }
    return !(strncmp(first, second, (strlen(first))));
}