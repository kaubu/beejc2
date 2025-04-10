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

[Previous](./3-variables-and-statements.md)
[Next](./5-pointers.md)