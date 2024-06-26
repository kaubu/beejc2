#include <stdio.h>

void plus_two(int *n)
{
    *n += 2;
}

int main(void)
{
    int n = 9;
    printf("n: %d\n", n);
    plus_two(&n);
    printf("n2: %d\n", n);
}
