#include <iostream>

int oldSpice(int thisto, int thepowerof);

int main() {
    std::cout << oldSpice(3,2) << std::endl;
    return 0;
}
int oldSpice(int thisto, int thepowerof){
    if (thepowerof == 1){
        return thisto;
    } else{
        return thisto * oldSpice(thisto, thepowerof - 1);
    }
}
