CC := "gcc"
# C version 2x
CVERSION := "-std=c2x -pedantic"
# All warnings set
CFLAGS := "-Wall -Wextra " + CVERSION

run path:
    {{CC}} {{CFLAGS}} {{path}}
    ./a.out
