#include <iostream>
#include <vector>

int main() {

    std::vector<std::string> listOfNames;
    std::cout << listOfNames.size() << std::endl;
    listOfNames.push_back("William");
    if (listOfNames.empty() == 1) {
        std::cout << "The list is empty." << std::endl;
    } else {
        std::cout << "The list is not empty." << std::endl;
    }
    listOfNames.push_back("John");
    listOfNames.push_back("Amanda");
    std::cout << listOfNames.size() << std::endl;
    std::cout << listOfNames.at(2) << std::endl;
    std::vector<std::string>::iterator i;
    for (i = listOfNames.begin(); i < listOfNames.end(); ++i) {
        std::cout << *i << std::endl;
    }
    for (int j = 0; j < listOfNames.size(); ++j) {
        std::cout << (j + 1) << ". " << listOfNames[j] << std::endl;
    }

    listOfNames.erase(listOfNames.begin()+1);

    for (i = listOfNames.end(); i >= listOfNames.begin(); --i) {
        std::cout << *i << std::endl;
    }
    listOfNames.clear();


    return 0;
}