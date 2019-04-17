#include <iostream>
#include <string>
#include "BlogPost.h"

int main() {
    std::string shortText = "Lorem ipsum dolor sit amet.";
    std::string mediumText = "A popular long-form, stick-figure-illustrated blog about almost everything.";
    std::string longText = "Daniel Hanley, a cybersecurity engineer at IBM, doesn’t want to be the center of attention. When I asked to take his picture outside one of IBM’s New York City offices, he told me that he wasn’t really into the whole organizer profile thing.";

    BlogPost post1("Lorem Ipsum", "John Doe", "2000.05.04", shortText);
    post1.showMe();
    BlogPost post2("Wait but why", "Tim Urban", "2010.10.10", mediumText);
    post2.showMe();
    BlogPost post3("One Engineer Is Trying to Get IBM to Reckon With Trump", "William Turton", "2017.03.28", longText);
    post3.showMe();

    return 0;
}