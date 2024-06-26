#include <stdio.h>

int main(void)
{
    int i;
    int *p;     // this is NOT a dereference, this is a type int-pointer

    p = &i;     // assign the address of i to p

    i = 10;
    printf("i is %d\n", i);     // prints "10"
    *p = 20;    // the thing p points to (namely i) is now 20!!

    printf("i is now %d\n", i);     // prints "20"
    printf("*p is %d\n", *p);   // prints "20"
}
