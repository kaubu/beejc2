#include <stdio.h>

void increment(int *p)  // it accepts a pointer to an int
{
    *p = *p + 1;    // add 1 to the thing p points to
}

int main(void)
{
    int i = 10;
    int *j = &i;    // note the address-of; turns it into a pointer to i

    printf("i is %d\n", i);         // prints "10"
    printf("is is also %d\n", *j);  // prints "10"

    increment(j);

    printf("i is %d\n", i);         // prints "11"

    increment(&i);  // manual address-of

    printf("i is %d\n", i);         // prints "12"
}
