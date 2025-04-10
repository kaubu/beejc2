#include <stdio.h>

int my_strlen(char *s)
{
    int count = 0;

    while (s[count] != '\0') {  // Single quotes for single char
        count++;
    }

    return count;
}

int main(void)
{
    char *s = "test";
    char *t = "abcdefg";
    char *u = "Hello, World!";

    printf("%s has a length of %d\n", s, my_strlen(s));
    printf("%s has a length of %d\n", t, my_strlen(t));
    printf("%s has a length of %d\n", u, my_strlen(u));
}