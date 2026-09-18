#include <stdio.h>
#include <unistd.h>
#include <stdbool.h> // Required for bool, true, and false in C

bool softlink(const char *source, const char *destination)
{
    if (symlink(source, destination) == 0)
    {
        printf("softlink created successfully \n%s -> %s\n", source, destination);
        return true;
    }
    else
    {
        perror("error creating softlink");
        return false;
    }
}

bool hardlink(const char *source, const char *destination)
{
    if (link(source, destination) == 0)
    {
        printf("hardlink is created successfully \n%s -> %s\n", source, destination);
        return true;
    }
    else
    {
        perror("error in creating hardlink");
        return false;
    }
}

int main()
{
    // Declaring string literals as constant character pointers
    const char *source = "original.txt";
    const char *d1 = "softlink.txt";
    const char *d2 = "hardlink.txt";

    printf("--------making links---------\n");

    softlink(source, d1);
    hardlink(source, d2);

    return 0;
}
