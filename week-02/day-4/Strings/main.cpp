#include <iostream>
#include <string>

std::string changeString(std::string input, int length);

int main() {
    std::string lalala = "xalla";
    int lelength = lalala.size();
    std::cout << changeString(lalala, lelength) << std::endl;
    return 0;
}

std::string changeString(std::string input, int length){
    if(length == 0){
    return input;
    }else{
        std::string
        return changeString(input, length - 1);
    }
}


// Given a string, compute recursively (no loops) a new string where all the lowercase 'x' chars have been changed to 'y' chars.