#include <stdio.h>

int main(void)
{
    char s[] = "Hello, World!";

    for (int i = 0; i < 13; i++) {
        printf("%c", s[i]);
    }

    printf("\n");
}