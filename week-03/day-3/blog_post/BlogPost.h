//
// Created by Nico on 17/04/2019.
//

#ifndef BLOG_POST_BLOGPOST_H
#define BLOG_POST_BLOGPOST_H


class BlogPost {
public:
    BlogPost(std::string newTitleOfPost, std::string newNameOfAuthor, std::string newDateOfPublishing,
             std::string newTextInThePost);

    void setTitleOfPost(std::string);

    void setNameOfAuthor(std::string);

    void setDateOfPublishing(std::string);

    void setTextInThePost(std::string);

    std::string &getTitleOfPost();

    std::string &getNameOfAuthor();

    std::string &getDateOfPublishing();

    std::string &getTextInThePost();

    std::string showMe();

    ~BlogPost();

private:
    std::string titleOfPost;
    std::string nameOfAuthor;
    std::string dateOfPublishing;
    std::string textInThePost;


};


#endif //BLOG_POST_BLOGPOST_H
