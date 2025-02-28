# beejc2

## Development environment

1. Install the C/C++ extension
2. Hit Ctrl + Alt + B to build a file while in it
3. Hit Ctrl + Alt + R to run the build

## Notes

### Style guide

#### Curly braces

Put curly braces on a new line when defining functions:

```c
int main(void)
{
    return 1;
}
```

Put curly braces on the same line when inside functions with things that can
nest:

```c
#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 10; i++) {
        for (int j = 10; i < 20, j++) {
            printf("%d + %d = %d", i, j, i + j);
        }
    }
}
```

### Table of Contents

1. N/A
2. [Hello World](./notes/2-hello-world.md)
3. [Variables](./notes/3-variables-and-statements.md)
4. [Functions](./notes/4-functions.md)
5. [Pointers](./notes/5-pointers.md)
6. [Arrays](./notes/6-arrays.md)
7. [Strings](./notes/7-string.md)

## Errors

* In chapter 7.3, it claims that some code will print out "all the characters in a string on the same line", but as it uses a newline `\n`, they do not print on the same line, unless said line is vertical.

