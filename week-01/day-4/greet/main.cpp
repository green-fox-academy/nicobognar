#include <iostream>
#include <string>

void greet(std::string);
int main(int argc, char* args[]) {

    // - Create a string variable named `al` and assign the value `Greenfox` to it
    std::string al = "Greenfox";
    // - Create a function called `greet` that greets it's input parameter
    greet(al);
    // - Greeting is printing e.g. `Greetings dear, Greenfox`
    // - Greet `al`

    return 0;
}
void greet(std::string a){
    std::cout << "Greetings, dear ";
    std::cout << a ;
}