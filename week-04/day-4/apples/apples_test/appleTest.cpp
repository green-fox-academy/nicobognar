//
// Created by Nico on 25/04/2019.
//
#include <gtest/gtest.h>
#include "apple.h"

TEST(apple_check, test_appleReturnsCorrectString){
    ASSERT_EQ(getApple(), "apple");
}

TEST(apple_sum_test, test_sumIsWorking){

    std::vector<int> testVector;
    testVector.push_back(16);
    testVector.push_back(23);
    testVector.push_back(3);
    testVector.push_back(6);

    EXPECT_EQ(sum(testVector), 48);

    ASSERT_EQ(sum(testVector), 49);

}