//
// Created by Nico on 17/04/2019.
//

#include "Counter.h"

Counter::Counter(int newIValue) {
    modifiedNumber = newIValue;
    initialNumber = newIValue;
}

Counter::Counter() {
    modifiedNumber = 0;
    initialNumber = 0;
}
void Counter::add(int addValue) {
    Counter::modifiedNumber += addValue;
}
void Counter::add(){
    ++modifiedNumber;
}
int Counter::get(){
    return modifiedNumber;
}
void Counter::reset(){
    modifiedNumber = initialNumber;
}
Counter::~Counter(){

}
