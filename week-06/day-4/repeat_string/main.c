#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void repeat_string(char *input_string, int amount_of_times);

int main()
{
    char *why_would_you_repeat_that;
    why_would_you_repeat_that = malloc(sizeof(char) * 30);
    int *this_many_times;
    this_many_times = calloc(4, sizeof(int));
    puts("Please enter a string you wish to repeat: ");
    gets(why_would_you_repeat_that);
    why_would_you_repeat_that = (char *) realloc(why_would_you_repeat_that, strlen(why_would_you_repeat_that) * sizeof(char));
    printf("Please enter the number of times you want the string to repeat itself: \n");
    scanf(" %d", this_many_times);
    repeat_string(why_would_you_repeat_that, *this_many_times);

    free(why_would_you_repeat_that);
    why_would_you_repeat_that = NULL;
    free(this_many_times);
    this_many_times = NULL;
    return 0;
}

void repeat_string(char *input_string, int amount_of_times)
{
    for (int i = 0; i < amount_of_times; ++i) {
        printf("%s", input_string);
    }
}
