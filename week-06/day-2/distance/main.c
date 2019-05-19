#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurrence of character 's'

int s_to_s(char string[]);

int main ()
{
    char str[] = "This is a sample string";
    printf("%d",s_to_s(str));

    return 0;
}

int s_to_s(char string[])
{
    int first = 0;
    int second = 0;
    for (int i = 0; i < strlen(string); ++i) {
        if (string[i] == 's'){
            if (first == 0){
                first = i+1;
            } second = i+1;
        }
    }
    return (second - first);
}
