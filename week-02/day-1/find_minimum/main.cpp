#include <iostream>

int *arrayMinimumScan(int fullRange[], int length);

int main()
{
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int *minimumValue = arrayMinimumScan(numbers, length);
    std::cout << *minimumValue << std::endl;

    return 0;
}
int *arrayMinimumScan(int fullRange[], int length){

    int minValue = fullRange[0];
    int index = 0;

    for(int i = 0; i < length; ++i){
        if(minValue > fullRange[i]){
            minValue = fullRange[i];
            index = i;
        }
    }

    return fullRange + index;
}