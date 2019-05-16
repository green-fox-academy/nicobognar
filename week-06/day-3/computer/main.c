#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer computer_one;
    computer_one.cpu_speed_GHz = 5;
    computer_one.ram_size_GB = 16;
    computer_one.bits = 64;

    Notebook notebook_one;
    notebook_one.cpu_speed_GHz = 2.47;
    notebook_one.ram_size_GB = 8;
    notebook_one.bits = 32;

    printf("This computer's processor runs at %.2f GHz, has %d GB RAM, and is a %d-bit system.\n", computer_one.cpu_speed_GHz, computer_one.ram_size_GB, computer_one.bits);
    printf("This computer's processor runs at %.2f GHz, has %d GB RAM, and is a %d-bit system.\n", notebook_one.cpu_speed_GHz, notebook_one.ram_size_GB, notebook_one.bits);
    return 0;
}