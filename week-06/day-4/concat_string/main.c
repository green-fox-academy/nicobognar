#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

void concatenate_these_strings(char *this, char *to_that);

int main()
{
    puts("What would you like to concatenate?");
    char *second_string_ptr;
    second_string_ptr = (char *) malloc(sizeof(char) * 30);
    gets(second_string_ptr);
    second_string_ptr = (char *) realloc(second_string_ptr, sizeof(char) * (strlen(second_string_ptr) + 1));
    puts("What would you like to concatenate to?");
    char *first_string_ptr;
    first_string_ptr = (char *) malloc(sizeof(char) * 30);
    gets(first_string_ptr);
    first_string_ptr = (char *) realloc(first_string_ptr, sizeof(char) * (strlen(first_string_ptr) + 1));
    concatenate_these_strings(first_string_ptr, second_string_ptr);
    printf("Your concatenation result is: %s", first_string_ptr);
    free(first_string_ptr);
    first_string_ptr = NULL;
    free(second_string_ptr);
    second_string_ptr = NULL;
    return 0;
}

void concatenate_these_strings(char *this, char *to_that)
{
    this = (char *)realloc(this, ((strlen(to_that)+strlen(this)) * sizeof(char) + 1));
    strcat(this, to_that);
}
