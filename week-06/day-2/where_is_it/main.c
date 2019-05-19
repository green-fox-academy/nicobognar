#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int where_is_it(char char_scan, char *string_scan);

int main()
{
    char *given_string;
    char given_char;
    printf("Please enter a word you wish to scan: \n");
    scanf(" %s", given_string);
    printf("Please enter a character you wish to scan the word for: ");
    scanf(" %c", &given_char);
    printf("The index of the given character occurring in your word is: %d", where_is_it(given_char, given_string));


    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"
    //

    return 0;
}

int where_is_it(char char_scan, char *string_scan)
{
    for (int i = 0; i < strlen(string_scan); ++i) {
        if (string_scan[i] == char_scan)
            return i;
    }
    return -1;
}
