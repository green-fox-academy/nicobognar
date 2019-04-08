#include <iostream>

int main ()
{
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    int *ptrA = &a;
    double b = 432.2;
    double *ptrB = &b;
    std::string name = "Bob";
    std::string *pointerName = &name;
    std::cout << *ptrA << std::endl;
    std::cout << *ptrB << std::endl;
    std::cout << *pointerName<< std::endl;


    return 0;
}