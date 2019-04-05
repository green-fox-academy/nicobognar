#include <iostream>

int main(int argc, char *args[]) {



    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    float semester = 5 * 17;
    float dailyhours = 6.00;
    // float weeklyhours = 30.000;
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    std::cout << semester * dailyhours << std::endl;
    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52
    float avgworkinghoursfull = 52 * 17;
    float codinghours = (semester * dailyhours) / avgworkinghoursfull;
    std::cout << codinghours * 100 << "%" << std::endl;
    return 0;
}