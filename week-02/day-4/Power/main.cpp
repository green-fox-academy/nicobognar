#include <iostream>

int oldSpice(int thisto, int thepowerof);

int main() {
    std::cout << oldSpice(4,2) << std::endl;
    return 0;
}
int oldSpice(int thisto, int thepowerof){
    thepowerof + 2;
    if (thisto >= 1 && thepowerof >= 1){
        return ((thisto * thisto)* (thepowerof - 1));
    }
}
