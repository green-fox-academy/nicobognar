//
// Created by Nico on 17/04/2019.
//

#ifndef COUNTER_COUNTER_H
#define COUNTER_COUNTER_H


class Counter {
public:
    Counter(int newIValue);

    Counter();

    void setInitialNumber(int initialNumber);

    void add();

    void add(int addThisNumber);

    int get();

    void reset();

    ~Counter();

private:
    int modifiedNumber;
    int initialNumber = 0;

};


#endif //COUNTER_COUNTER_H
