#include <stdio.h>

int main()
{
    char *name = "CrashBandicoot";
    name[10] = 'a';
    printf("%s", name);

    return 0;
}