#include <stdio.h>

int main(void)
{
    int a = 999;

    // %zu is the format specifier for type size_t

    printf("%zu\n", sizeof a);          // prints 4 on my system
    printf("%zu\n", sizeof (2 + 7));    // prints 4 on my system
    printf("%zu\n", sizeof 3.14);       // prints 8 on my system
}
