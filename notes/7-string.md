### 7 - Strings
Strings aren't strings, but pointers. Like arrays, strings in C *barely exist*.

#### 7.1 - String Literals

...

#### 7.2 - String Variables

Creating a string literal:

```c
char *s = "Hello, world!";
```

The string variable `s` is actually a pointer to the first character in that string, mainly the `H`.

We can print it with the `%s` (for "string") format specifier:

```c
char *s = "Hello, world!";

printf("%s\n", s); // "Hello, world!"
```

#### 7.3 - String Variables as Arrays

Another option to create strings is to use arrays, which is nearly equivalent to the above `char*` usage:

```c
char s[14] = "Hello, world!";

// or, if we were properly lazy and have the compiler
// figure the length for us:

char s[] = "Hello, world!";
```

This means you can use array notation to access characters in a string.

Here's how we can print all the characters in a string on the same line using array notation:

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

Also, the program will still work fine if we change the definition of `s` to be a `char*` type:

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

