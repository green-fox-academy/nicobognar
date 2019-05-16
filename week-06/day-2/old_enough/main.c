#include <stdio.h>
#include <stdlib.h>

int are_they_old_enough(int age);

int main()
{
    // Create a program which asks for the age of the user and stores it
    // Create a function which takes that age as a parameter and returns if the user is
    // old enough to buy himself alcohol in Hungary
    int user_age = 0;
    printf("Please enter your age: \n");
    scanf("%d", &user_age);
    //printf("You %s old enough to legally buy alcohol in Hungary.", are_they_old_enough(user_age));
    printf("You %s old enough to legally buy alcohol in Hungary.", are_they_old_enough(user_age) ? "are" : "are not");

    return 0;
}
int are_they_old_enough(int age)
{
    if (age > 17){
        return 1;
    } else return 0;
   //return age > 17 ? "are" : "are not";

}