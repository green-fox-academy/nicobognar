//
// Created by Nico on 17/04/2019.
//
#include <string>
#include "BlogPost.h"
#include <iostream>

BlogPost::BlogPost(std::string newTitleOfPost, std::string newNameOfAuthor, std::string newDateOfPublishing,
                   std::string newTextInThePost) {
    setTitleOfPost(newTitleOfPost);
    setDateOfPublishing(newDateOfPublishing);
    setNameOfAuthor(newNameOfAuthor);
    setTextInThePost(newTextInThePost);

}

void BlogPost::setTitleOfPost(std::string titleChange) {
    BlogPost::titleOfPost = titleChange;
}

void BlogPost::setNameOfAuthor(std::string authorChange) {
    BlogPost::nameOfAuthor = authorChange;
}

void BlogPost::setDateOfPublishing(std::string dateChange) {
    BlogPost::dateOfPublishing = dateChange;
}

void BlogPost::setTextInThePost(std::string textChange) {
    BlogPost::textInThePost = textChange;
}

std::string &BlogPost::getTitleOfPost() {
    return titleOfPost;
}

std::string &BlogPost::getNameOfAuthor() {
    return nameOfAuthor;
}

std::string &BlogPost::getDateOfPublishing() {
    return dateOfPublishing;
}

std::string &BlogPost::getTextInThePost() {
    return textInThePost;
}

std::string BlogPost::showMe() {
    std::cout << getTitleOfPost() << "titled by " << getNameOfAuthor() << "posted on " << getDateOfPublishing()
              << std::endl;
    std::cout << getTextInThePost() << std::endl;
}

BlogPost::~BlogPost() {
}

