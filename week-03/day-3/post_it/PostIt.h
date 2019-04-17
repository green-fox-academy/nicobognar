//
// Created by Nico on 17/04/2019.
//
#ifndef POST_IT_POSTIT_H
#define POST_IT_POSTIT_H
#include <string>
#include <iostream>


class PostIt {
public:
    PostIt(std::string newBackgroundColor, std::string newText, std::string newTextColor);

    void setBackgroundColor(std::string newBackgroundColor);

    void setText(std::string newText);

    void setTextColor(std::string newTextColor);

    std::string &getBackgroundColor();

    std::string &getText();

    std::string &getTextColor();

    std::string showMe();

private:
    std::string backgroundColor;
    std::string text;
    std::string textColor;
};


#endif //POST_IT_POSTIT_H
