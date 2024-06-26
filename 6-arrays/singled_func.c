#include <stdio.h>

// Passing a pointer as the first element
void times2(int *a, int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d x 2 = %d\n", a[i], a[i] * 2);
    }
}

// Same thing, but with array notation
void times3(int a[], int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d x 3 = %d\n", a[i], a[i] * 3);
    }
}

// Same thing, but with array notation with size
void times4(int a[5], int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d x 4 = %d\n", a[i], a[i] * 4);
    }
}

int main(void)
{
    int x[5] = {11, 22, 33, 44, 55};

    times2(x, 5);
    times3(x, 5);
    times4(x, 5);
}
