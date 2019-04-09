#include <iostream>
#include <map>
#include <vector>

int main() {

    std::map<int, std::string> thisIsMyMap;
    if (thisIsMyMap.empty() != 0) {
        std::cout << "My map is  empty." << std::endl;
    } else {
        std::cout << "My map is NOT empty." << std::endl;
    }
    thisIsMyMap.insert(std::make_pair(97, "a")); //thisIsMyMap[97] = "a";
    thisIsMyMap.insert(std::make_pair(98, "b")); //thisIsMyMap[98] = "b";
    thisIsMyMap.insert(std::make_pair(99, "c")); //thisIsMyMap[99] = "c";
    thisIsMyMap.insert(std::make_pair(65, "A")); //thisIsMyMap[65] = "A";
    thisIsMyMap.insert(std::make_pair(66, "B")); //thisIsMyMap[66] = "B";
    thisIsMyMap.insert(std::make_pair(67, "C")); //thisIsMyMap[67] = "C";

    std::map<int, std::string>::iterator mapIterator;

    for (mapIterator = thisIsMyMap.begin(); mapIterator != thisIsMyMap.end(); ++mapIterator) {
        std::cout << mapIterator->first << std::endl;
    }
    for (mapIterator = thisIsMyMap.begin(); mapIterator != thisIsMyMap.end(); ++mapIterator) {
        std::cout << mapIterator->second << std::endl;
    }
    thisIsMyMap[68] = "D";
    std::cout << thisIsMyMap.size() << std::endl;
    std::cout << thisIsMyMap.at(99) << std::endl;
    thisIsMyMap.erase(97);
    if(thisIsMyMap.find(100) != thisIsMyMap.end()){
        std::cout << "There is a key 100." << std::endl;
    }else {
        std::cout << "There isn't a key 100." << std::endl;
    }
    thisIsMyMap.clear();


    return 0;
}