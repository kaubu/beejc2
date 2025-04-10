#include <stdio.h>

int main(void)
{
    char s[] = "Hello, world!";
    char *t;

    // This makes a copy of the pointer, not a copy of the string
    t = s;

    // We modify t
    // This works because it's a pointer to an array
    t[0] = 'z';

    // But printing s shows the same modification!
    // Because t and s point to the same string!

    printf("%s\n", s);  // "zello, world!"
}