#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *append_a_to_the_end(char needs_vitamin_a[]);

int main()
{
    char string_lacking_a[30];
    printf("Please enter a word or a sentence: \n");
    scanf("%s", string_lacking_a);
    printf("Here's your input with my a-ddition: \n %s", append_a_to_the_end(string_lacking_a));

    return 0;
}

char *append_a_to_the_end(char needs_vitamin_a[])
{
    char append_this = 'a';
    strcat(needs_vitamin_a, &append_this);
    return needs_vitamin_a;
}
