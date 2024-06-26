# The C compiler
CC := "gcc"
# C version 2x
# -std=VER = sets the C version standard to VER
# -ansi = turns off features of GCC incompatible with the ANSI standard
#   -ansi is equivalent to -std=c89.
# -pedantic = tells the compiler to adhere strictly to the version and standard
# -pedantic-errors = stricter version of -pedantic that turns warnings into
#   errors.
CVERSION := "-std=c2x -pedantic"
# Error levels
# -Wall = enables a set of warnings, but not actually all
# -Wextra = enables extra warnings
# -Werror = treats warnings as errors
CELVL := "-Wall -Wextra"
# C optimization level
# -O1–3 = optimize as much as possible, with 1 being least and 3 being most.
# -O0 = the default. turn off optimization for faster compilation time.
# -Os = optimize for size. enables all -O2 options that don't increase size.
#   also does more optimizations to reduce size.
COPT := "-O0"
# All warnings set
CFLAGS := CELVL + " " + COPT + " " + CVERSION

run path:
    {{CC}} {{CFLAGS}} {{path}}
    ./a.out
