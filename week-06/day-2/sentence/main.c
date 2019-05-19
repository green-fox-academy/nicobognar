#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter,
// and splits a string to words by space
// solve the problem with the proper string.h function

void separate_by_space(char sentence[]);

int main()
{
    printf("Type in a sentence: \n");
    char string[256];
    gets(string);
    separate_by_space(string);

    return(0);
}

void separate_by_space(char sentence[])
{
    char *p = strtok(sentence, " ");
    while( p != NULL){
        puts(p);
        p = strtok(NULL, " ");
    }
}
