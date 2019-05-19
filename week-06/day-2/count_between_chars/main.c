#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_between_chars(char *word, char character);

int main()
{
    // Create a function which takes a string as a parameter and
    // returns the number of characters between two repeating characters
    // the repeating char can be a local variable in the function itself or
    // it can be passed to the function as parameter

    char *word = "Programming";

    // the output should be: 6 (in this case the repeating char was 'g')
    printf(" %d", count_between_chars(word, 'g'));

    return 0;
}

int count_between_chars(char *word, char character)
{
    int first_time = 0;
    int second_time = 0;
    for (int i = 0; i < strlen(word); ++i) {
        if (word[i] == character){
            if (first_time == 0){
                first_time = i;
            } second_time = i;
        }
    }
    return ((second_time - first_time) - 1);
}