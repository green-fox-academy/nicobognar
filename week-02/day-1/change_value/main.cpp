#include <iostream>
void changeTemp(float *randomTemperature);
int main ()
{
    // Change the value of the variable called 'temperature' using a pointer
    // (you have to create the pointer first)

    float temperature = 21.3;
    float *temperaturePointer = &temperature;
    changeTemp(temperaturePointer);
    std::cout << temperature << std::endl;

    return 0;
}

void changeTemp(float *randomTemperature){
    *randomTemperature += 2;
}

