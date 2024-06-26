# beejc2

## Development environment

1. Install the C/C++ extension
2. Hit Ctrl + Alt + B to build a file while in it
3. Hit Ctrl + Alt + R to run the build

## Notes

### Style guide



### 2 - Hello World

The `printf()` functions requires the `stdio.h` header file.

### 3 - Variables and statements

#### 3.1 Variables

##### 3.1.2 Variable Types

C makes an effort to convert automatically between most numeric types when you
ask it to. But other than that, all conversions are manual, notably between
string and numeric.

<hr/>

`printf()` format strings:

* `%d` - integers. think d as in digit.
* `%f` - floating point numbers.
* `%s` - strings / char pointers.
* `%p` - pointer addresses. must be cast to a void pointer.
* `%zu` - type size_t.

##### 3.1.3 Boolean Types

To use the `bool` type, you must include `stdbool.h`.

#### 3.2 Operators and Expressions

##### 3.2.1 Arithmetic

There is no exponentiation. You have to use one of the `pow()` variants from
`math.h`.

##### 3.2.3 Pre-and-Post Increment-and-Decrement

Pre-increment and -decrement is used frequently with array and pointer access
and manipulation. It gives you a way to use the value in a variable, and also
increment or decrement that value before or after it is used.

##### 3.2.4 The Comma Operator

This is an uncommonly-used way to separate expressions that will run left to
right:

```c
x = 10, y = 20;  // First assign 10 to x, then 20 to y
```

It's different from separating with a semicolon since using a semicolon results
in **two** statements, but a comma results in **one**.

<hr/>

With the comma operator, the value of the comma expression is the value of the
rightmost expression:

```c
x = (1, 2, 3);

printf("x is %d\n", x);  // Prints 3, because 3 is rightmost in the comma list
```

One common place the comma operator is used is in `for` loops to do multiple
things in each section of the statement:

```c
for (i = 0, j = 10; i < 100; i++, j++)
    printf("%d, %d\n", i, j);
```

##### 3.2.7 The `sizeof` operator

This operator tells you the size (in bytes) that a particular variable or data
type uses in memory.

More particularly, it tells you the size (in bytes) that the *type of a
particular expression* (which might be just a single variable) uses in memory.

This can be different on different systems, except for char and its variants
(which are always 1 byte).

> C has a special type to represent the return value from sizeof. It’s `size_t`.

`size_t` shows up a lot of different places where counts of things are passed
or returned. Think of it as a value that represents a count.

You can take the `sizeof` a variable or expression:

```c
int a = 999;

// %zu is the format specifier for type size_t

printf("%zu\n", sizeof a);
printf("%zu\n", sizeof (2 + 7));
printf("%zu\n", sizeof 3.14);
```

`sizeof` is a compile-time operation.

#### 3.3 Flow Control

##### 3.3.3 The do-while statement

Do `rand()` (`stdlib.h`) to get a random number. You must seed it first with `srand()`,
however. You can seed `srand()` with `time(NULL)` (in the `time.h` header),
according to the POSIX spec—but not the C spec—returns exactly the number of
seconds since the Unix epoch, 1 January 1970.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int r;

    do {
        r = rand() % 100;   // Get a random number between 0 and 99
        printf("%d\n", r);
    } while (r != 37);
}
```

### 4 - Functions

`void` in function parameters indicates that the function accepted no
arguments:

```c
int main(void)
{
    return 0;
}
```

You can return `void` to indicate that you don't return a value:

```c
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
```

returns:

```sh
gcc -Wall -Wextra -std=c2x -pedantic 4-functions/void_return.c
./a.out
n: 9
n2: 11
```

#### 4.3 Empty Parameter Lists

Not putting `void` in the parameter list means that C will turn off all type
checking. It tells the compiler that there's no information about what might be
entered.

In function definitions is one thing, but in a function prototype you should
**definitely** use `void` when you have an empty parameter list.

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
