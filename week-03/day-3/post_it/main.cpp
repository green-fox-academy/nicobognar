#include <iostream>
#include <string>
#include "PostIt.h"

int main() {
    PostIt idea1("orange", "Idea", "blue");
    idea1.showMe();
    PostIt idea2("pink", "Awesome", "black");
    idea2.showMe();
    PostIt idea3("yellow", "Superb!", "green");
    idea3.showMe();


    return 0;
}