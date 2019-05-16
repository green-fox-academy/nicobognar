#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int number_of_lines_in_file(char *file_name);

int main ()
{
    printf("%d", number_of_lines_in_file("../my-file.txt"));
    return 0;
}

int number_of_lines_in_file(char *file_name)
{
    FILE *file_pointer = fopen(file_name, "r");
    if(file_pointer == NULL){
    return 0;
    } else {
        char buffer[40];
        int number_of_lines = 0;
        while (fgets(buffer, 40, file_pointer) != NULL){
            ++number_of_lines;
        }
        return number_of_lines;
    }
}
