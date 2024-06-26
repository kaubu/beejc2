#include <stdio.h>

int main(void)
{
    int i;
    int a[5] = {1, 2, 3, 4, 5};

    for (i = 0; i < 10; i++)    // BAD NEWS: printing too many elements!
    {
        printf("%d\n", a[i]);
    }
}
