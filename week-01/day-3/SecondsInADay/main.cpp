#include <iostream>

int main(int argc, char *args[]) {

    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;

    int remainingHours = 23 - currentHours;
    int remainingMinutes = 60 - currentMinutes;
    int remainingSeconds = 60 - currentSeconds;

    int remainingHoursInSeconds = remainingHours * 60;
    int remainingMinutesInSeconds = remainingMinutes * 60;

    std::cout << "There are " << (remainingHoursInSeconds + remainingMinutesInSeconds + remainingSeconds)
              << "seconds left of today." << std::endl;
    // ignore the line below
    // std::cout << "There are " << remainingHours << " hour(s), " << remainingMinutes << " minute(s), and " << remainingSeconds << " second(s) left of today." << std::endl;

    // Write a program that prints the remaining seconds (as an integer) from a
    // day if the current time is represented by the variables

    return 0;
}