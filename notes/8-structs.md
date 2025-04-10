### 8 Structs

A `struct` is a user-definable type that holds multiple pieces of data,
potentially of different types.

It's a convenient way to bundle multiple variables into a single one.

Structs are similar to *classes* annd *objects*, except with only data members
and no methods.

#### 8.1 Declaring a Struct

You can declare a struct like so:

```c
struct car {
    char *name;
    float price;
    int speed;
};
```

This is often done at the global scope outside any functions so that the struct
is globally available.

When you do this, you're making a new *type*. The full type name is `struct
car`. (Not just `car`, that won't work.)

Let's declare a variable of that type:

```c
struct car saturn;  // Variable "saturn" of type "struct car".
```

And now we have an uninitialized variable `saturn` of type `struct car`.

We should initialize it! How? We can use the dot operator (`.`) to access the
individual fields:

```c
saturn.name = "Saturn SL/2";
saturn.price = 15999.99;
saturn.speed = 175;

printf("Name:           %s\n", saturn.name);
printf("Price (USD):    %f\n", saturn.price);
printf("Top Speed (km): %d\n", saturn.speed);
```

#### 8.2 Struct Initializers

The example in the previous section was a little unwieldy. There is a better
way to initialize the struct variable.

You can do it with ann initializer by puttinng values in for the fields *in the
order they appear in the `struct` when you define the variable*. This won't
work after the variable has been definned - it has to be in the definition.

```c
#include <stdio.h>

struct car {
    char *name;
    float price;
    int speed;
};

int main(void)
{
    struct car saturn = {"Saturn SL/2", 16000.99, 175};

    printf("Name:      %s\n", saturn.name);
    printf("Price:     %f\n", saturn.price);
    printf("Top Speed: %d km\n", saturn.speed);
}
```

The fact that the initializer needs to be in the same order is a little freaky.
If someone changes the order in `struct car`, it could break all the other
code!

So to be more specific with our initializers:

```c
struct car saturn = {.speed=175, .name="Saturn SL/2"};
```

Now it's independent of the order in the `struct` definition. It's safer code
now for sure.

Similar to array initializers, any missing field designators are initialized to
zero (in this case, that would be `.price`, which I've omitted).

#### 8.3 Passing Structs to Functions


