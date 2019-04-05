#include <iostream>
#include <cmath>

int main(int argc, char *args[]) {

    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4
    float userfirstnumber;
    float usersecondnumber;
    float userthirdnumber;
    float userfourthnumber;
    float userfifthnumber;


   // std::cout.precision(2);
    std::cout << "Please enter your first number: ";
    std::cin >> userfirstnumber;
    std::cout << "Thank you! Now please enter your second number: ";
    std::cin >> usersecondnumber;
    std::cout << "Thank you! Now please enter your third number: ";
    std::cin >> userthirdnumber;
    std::cout << "Thank you! Now please enter your fourth number: ";
    std::cin >> userfourthnumber;
    std::cout << "Thank you! Now please enter your fifth number: ";
    std::cin >> userfifthnumber;
    float averageofall = ((userfirstnumber + usersecondnumber + userthirdnumber + userfourthnumber + userfifthnumber) / 5);
    std::cout << "Sum: " << (userfirstnumber + usersecondnumber + userthirdnumber + userfourthnumber + userfifthnumber) << " , and the average is: " << averageofall << "." << std::endl;





    return 0;
}