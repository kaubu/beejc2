#include <stdio.h>

void foo(int x[12])
{
    printf("%zu\n", sizeof x);      // 8?! What happened to 48?
    printf("%zu\n", sizeof(int));   // 4 bytes per int

    printf("%zu\n", sizeof x / sizeof(int));    // 8/4 = 2 ints??? WRONG.
}

int main(void)
{
    int x[12];

    printf("%zu\n", sizeof x);      // 48 bytes
    printf("%zu\n", sizeof(int));   // 4 bytes

    printf("%zu\n", sizeof x / sizeof(int));    // 48 / 4 bytes = 12 ints

    printf("----\n");

    foo(x);

    printf("45 elements of type double is %zu bytes\n", sizeof(double [45]));
}
