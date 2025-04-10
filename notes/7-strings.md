### 7 - Strings
Strings aren't strings, but pointers. Like arrays, strings in C *barely exist*.



#### 7.1 - String Literals

...

#### 7.2 - String Variables

Creating a string literal:

```c
char *s = "Hello, world!";
```

The string variable `s` is actually a pointer to the first character in that
string, mainly the `H`.

We can print it with the `%s` (for "string") format specifier:

```c
char *s = "Hello, world!";

printf("%s\n", s); // "Hello, world!"
```

#### 7.3 - String Variables as Arrays

Another option to create strings is to use arrays, which is nearly equivalent
to the above `char*` usage:

```c
char s[14] = "Hello, world!";

// or, if we were properly lazy and have the compiler
// figure the length for us:

char s[] = "Hello, world!";
```

This means you can use array notation to access characters in a string.

Here's how we can print all the characters in a string on the same line using
array notation:

```c
#include <stdio.h>

int main(void)
{
    char s[] = "Hello, World!";

    for (int i = 0; i < 13; i++) {
        printf("%c\n", s[i]);
    }
}
```

Note that we're using the format specifier `%c` to print a single character.

Also, the program will still work fine if we change the definition of `s` to be
a `char*` type:

```c
#include <stdio.h>

int main(void)
{
    char s* = "Hello, World!";

    for (int i = 0; i < 13; i++) {
        printf("%c\n", s[i]);
    }
}
```

And we can still use array notation!

This is a hint that pointers and arrays are the same thing deep down.

#### 7.4 - String Initializers

The two initializers:

```c
char *s = "Hello, world!";
char t[] = "Hello, again!";
```

are subtlely different.

A string literal, like an integer literal, has its memory automatically managed
by the compiler for you. Typically, the string literal is stored in read-only
memory for performance and safety reasons.

So, for example, trying to mutate it:

```c
char *s = "Hello, world!";

s[0] = 'z'; // BAD NEWS: tried to mutate a string literal!
```

This behaviour is undefined. Depending on your system, it will probably crash.

But declaring an array is different.

> The compiler doesn’t stow those bytes in another part of town, they’re right
> down the street.

This creates a mutable *copy* of the string - one we can change at will.

```c
char t[] = "Hello, again!"; // t is an array copy of the string
t[0] = 'z'; // no problem

printf("%s\n", t);  // "zello, again!"
```

So remember: **If you have a pointer to a string literal, don't try to change
it!** And if you use a string in double quotes to initialize an array, that's
not actually a string literal.

#### 7.5 - Getting String Length

You can't, since C doesn't track it for you. Though, there is a function in
`<string.h>` called `strlen()` that can be used to compute the length of any
string in bytes.

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *s = "Hello, world!";

    printf("The string is %zu bytes long.\n", strlen(s));
}
```

The `strlen()` function returns type `size_t`, which is an integer type so you
can use it for integer math. We print `size_t` with `%zu`.

The above program prints:

```
The string is 13 bytes long.
```

Great! So it *is* possible to get the string length.

But if C doesn't track the length of the string anywhere, how does it know how long the string is?

#### 7.6 - String Termination

C does strings differently than almost every modern programming language.

In C, a "string" is defined by two basic characteristics:

1. A pointer to the first character in the string
2. A zero-valued byte (or `NUL` character) somewhere in memory after the
   pointer that indicates the end of the string.

A`NUL` character cann be written in C code as `\0`, though you don't often have
to do this, because when you include a string in double quotes in your code, the `NUL` character is automatically, implicitly included.

```c
char *s = "Hello!"; // Actually "Hello!\0" behind the scenes
```

So let's write our own strlen function that counts `char`s in a string until it finds a `NUL`:

```c
int my_strlen(char *s)
{
    int count = 0;

    while (s[count] != '\0') {  // Single quotes for single char
        count++;
    }

    return count;
}
```

That's basically how the built-in `strlen()` gets the job done.

#### 7.7 - Copying a String

You can't copy a strinng using the assignment operator. All that does is a copy a pointer to the first character, so you end up with two pointers to the same string:

```c
#include <stdio.h>

int main(void)
{
    char s[] = "Hello, world!";
    char *t;

    // This makes a copy of the pointer, not a copy of the string
    t = s;

    // We modify t
    // This works because it's a pointer to an array
    t[0] = 'z';

    // But printing s shows the same modification!
    // Because t and s point to the same string!

    printf("%s\n", s);  // "zello, world!"
}
```

If you want to make a copy of the string, you have to copy it a byte at a time. This is made easier with the `strcpy()` function.

> **Before you copy the string, make sure you have room to copy it into,** i.e. the destination array that's going to hold the characters needs to be at least as long as the string you're copying.

```c
#include <stdio.h>
#include <string.h>

int main(void)
{
    char s[] = "Hello, world!";
    char t[100];    // Each char is 1 byte, so plenty of room

    // This makes a copy of the string
    strcpy(t, s);   // dest, src - like assembly

    // We modify t
    t[0] = 'z';

    // And s remains unaffected because it's a different string
    printf("%s\n", s);  // "Hello, world!"

    // But t has been changed
    printf("%s\n", t);  // "zello, world!"
}
```

> Notice with `strcpy()`, the destination pointer is the first argument and the
> source pointer is the second. A mnemonic you can use to remember this is that
> it's the order you would have put `t` and `s` if an assigment `=` worked for
> strings, with the source on the right and the destination on the left.

[Previous](./6-arrays.md)
[Next](./8-structs.md)