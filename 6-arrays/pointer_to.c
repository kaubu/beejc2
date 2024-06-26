#include <stdio.h>

int main(void)
{
    int a[5] = {11, 22, 33, 44, 55};
    int *p;

    p = &a[0];  // p points to the first element in an array

    printf("%d\n", *p); // prints "11"

    int *q;
    q = a;  // shorthand for q = &a[0];

    printf("%d\n", *q); // prints "11"
}
