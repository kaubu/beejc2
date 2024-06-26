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
