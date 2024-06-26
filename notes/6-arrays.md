### 6 - Arrays

C has arrays, but *barely*. Array syntax is just syntactic sugar for pointers
and stuff.

When you declare an array, you have to give it a size. And the size has to be
fixed.

#### 6.1 Easy Example

```c
#include <stdio.h>

int main(void)
{
    int i;
    float f[4];     // declare an array of 4 floats

    f[0] = 3.14159;     // indexing starts at 0, of course
    f[1] = 1.41421;
    f[2] = 1.61803;
    f[3] = 2.72828;

    // print them all out
    for (i = 0; i < 4; i++)
    {
        printf("%f\n", f[i]);
    }

    return 0;
}
```

#### 6.2 Getting the Length of an Array

You can't... ish. C doesn't store this information (since arrays are just
pointers to the first element of the array). You have to manage this separately
in another variable.

There are, however, circumstances where you *can*. There is a trick to get the
number of elements in an array in the scope in which an array is declared, but
this won't work if you pass the array to a function.

Let's take a look at this trick. The basic idea is you take the `sizeof` of the
array, then divide that by the size of each element's type to get the length.
For example, if an `int` is 4 bytes, and an array is 32 bytes long, then there
must be room for 32/4 = 8 ints.

```c
#include <stdio.h>

int main(void)
{
    int x[12];

    printf("%zu\n", sizeof x);      // 48 bytes
    printf("%zu\n", sizeof(int));   // 4 bytes

    printf("%zu\n", sizeof x / sizeof(int));    // 48 / 4 bytes = 12 ints
}
```

If it's an array of `char`s then `sizeof` the array *is* the number of
elements, since `sizeof(char)` is defined to be 1. For anything else, you have
to divide by the size of each element.

But this trick only works in the scope in which an array was defined. If you
pass the array to another function, it doesn't work.

```c
void foo(int x[12])
{
    printf("%zu\n", sizeof x);      // 8?! What happened to 48?
    printf("%zu\n", sizeof(int));   // 4 bytes per int

    printf("%zu\n", sizeof x / sizeof(int));    // 8/4 = 2 ints??? WRONG.
}
```

This is because when you "pass" arrays to functions, you're only passing the
pointer to the first element, and that's what `sizeof` measures. More on this
in the **Passing Single Dimensional Arrays to Functions** section below.

---

One more thing you can do with `sizeof` is get the size of an array of a fixed
number of elements without declaring the array. This is like how you can get
the size of an `int` with `sizeof(int)`:

```c
sizeof(double [48]);    // 360 bytes
```

#### 6.3 Array Initializers

You can initialize an array with constants ahead of time:

```c
int a[5] = {2, 4, 152, 5892, 424};
```

You should never have more elements than declared otherwise the compiler will
get angry. But, fun fact! You can have fewer elements. The remaining elements
will be initialized to 0.

```c
int a[5] = {22, 37, 3490};

// is the same as

int a[5] = {22, 37, 3490, 0, 0};
```

It's a common shortcut to see this as an initializer when you want to set an
entire array to 0:

```c
int a[5] = {0};
```

which means "make the first element zero, and then automatically set the others
to zero as well".

---

You can set specific array elements in the initializer, too, by specifying an
index for the value. The rest will be set to 0:

```c
int a[10] = {0, 11, 22, [5]=55, 66, 77};
// results in: 0 11 22 0 0 55 66 77 0 0
```

You can put constant expressions in there too:

```c
#define COUNT 5

int a[COUNT] = {[COUNT-3]=3, 2, 1, 0};
// which gives us:
// 0 0 3 2 1
```

Lastly you can make C compute the size of the array from the beginning just by
leaving the size off:

```c
int a[3] = {42, 52, 124};

// is the same as

int a[] = {42, 52, 124};
```

#### 6.4 Out of Bounds!

C doesn't stop you from accessing arrays out of bounds.

```c
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
```

Running it on my computer prints:

```
1
2
3
4
5
0
-732546816
239742591
-121118112
32766
```

Yikes. This is undefined behaviour. Essentially: don't do anything that causes
undefined behaviour. Ever.

#### 6.5 Multidimensional arrays

Multi-dimensional arrays:

```c
#include <stdio.h>

int main(void)
{
    // declaring
    int b[2][7];
    int c[4][5][6];

    int row, col;

    // initializing multi-dimensional arrays
    int a[2][5] = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9},
    };

    // looping over them
    for (row = 0; row < 2; row++) {
        for (col = 0; col < 5; col++) {
            printf("(%d,%d) = %d\n", row, col, a[row][col]);
        }
    }
}
```

#### 6.6 Arrays and Pointers

