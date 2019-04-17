//
// Created by Nico on 17/04/2019.
//
#include <iostream>
#include "PostIt.h"
#include <string>


PostIt::PostIt(std::string newBackgroundColor, std::string newText, std::string newTextColor){

    setBackgroundColor(newBackgroundColor);
    setText(newText);
    setTextColor(newTextColor);
}

void PostIt::setBackgroundColor(std::string newBackgroundColor) {
    backgroundColor = newBackgroundColor;
}

void PostIt::setText(std::string newText) {
    text = newText;
}

void PostIt::setTextColor(std::string newTextColor) {
    textColor = newTextColor;
}

std::string &PostIt::getBackgroundColor() {
    return backgroundColor;
}

std::string &PostIt::getText() {
    return text;
}

std::string &PostIt::getTextColor() {
    return textColor;
}

std::string PostIt::showMe(){
    std::cout << "This is a(n) " << getBackgroundColor() << " with " << getTextColor() << " text: " << getText() << " post-it." << std::endl;
}

