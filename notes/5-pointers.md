### 5 - Pointers

Get the memory address of a variable using the address-of operator, the
ampersand: `&`.

Pointer types are the type plus an asterisk `*`: `int *p`.

The dereference, or, in reality, the *indirection operator*, because you're
getting values indirectly via a pointer, is also an asterisk: `*`.

Putting it together:

```c
#include <stdio.h>

int main(void)
{
    int i;
    int *p;     // this is NOT a dereference, this is a type int-pointer

    p = &i;     // assign the address of i to p

    i = 10;
    printf("i is %d\n", i);     // prints "i is 10"
    *p = 20;    // the thing p points to (namely i) is now 20!!

    printf("i is now %d\n", i);     // prints "i is now 20"
    printf("*p is %d\n", *p);   // prints "*p is 20"
}
```

#### 5.5 The `NULL` pointer

Any pointer of any type can be set to a special value called `NULL`. This
indicates that the pointer doesn't point to anything.

```c
int main(void)
{
    int *p;

    p = NULL;
}
```

Since it doesn't point to a value, dereferencing it is undefined behaviour, and
will probably result in a crash:

```c
int main(void)
{
    int *p = NULL;

    *p = 12;        // CRASH or SOMETHING BAD. BEST AVOIDED.
}
```

Despite being called the billion-dollar mistake by its creator, the `NULL`
pointer is a good sentinel value and general indicator that a pointer hasn't
been initialized.

(Of course, like other variables, the pointer points to garbage unless you
explicitly assign it to point to an address or NULL.) 

#### 5.6 A Note on Declaring Pointers

If you declare multiple pointers and ints on the same line, it can get
confusing as to which is a pointer and what is not if the asterisk is by the
integer type:

```c
int* a, b;  // a is an int-pointer, b is an int
```

So it's better to type with the asterisk next to the identifier for clarity:

```c
int *a, b, *c, d, e, *f;
```

#### 5.7 sizeof and Pointers

The `sizeof` operator returns the size of the *type* of the expression, not the
value of any underlying values. So for example:

```c
int main(void)
{
    int *p;

    // prints the size of an 'int'
    printf("%zu\n", sizeof(int));

    // prints the size of an 'int-pointer', so prints the size of `int *`
    printf("%zu\n", sizeof p);

    // prints the size of an 'int', as the underlying value is dereferenced,
    // and the type is got from that
    printf("%zu\n", sizeof *p);
}
```
