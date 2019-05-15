#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main ()
{
    FILE *file_pointer;
    file_pointer = fopen("../my-file.txt", "w");
    fprintf(file_pointer, "The 5 minute journal\n is a very efficient way\n to keep your motivation stable.");
    fclose(file_pointer);

    FILE *lets_read_it;
    lets_read_it = fopen("../my-file.txt", "r");
    if (lets_read_it == NULL){
        printf("Unable to open file.");
    } else {
        char the_boar_is_pregnant[30];
        while (fgets(the_boar_is_pregnant, 30, lets_read_it) != NULL){
            fprintf(stdout, "%s", the_boar_is_pregnant);
        }
    }
    fclose(lets_read_it);
    return 0;
}