#include <iostream>

int main()
{
    // Add two numbers using pointers

    int a = 20;
    int *aPointer = &a;
    int b = 17;
    int *bPointer = &b;
    int result;
    int *resultPointer = &result;

    *resultPointer = ((*aPointer) + (*bPointer));



    return 0;
}