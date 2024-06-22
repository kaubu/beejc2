#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int i;
    i = 2;
    float f = 32;
    char *s = "Hello World!";

    printf("%s i = %d and f = %f\n", s, i, f);

    bool x = true;

    if (x)
    {
        printf("x is true!\n");
    }
}
