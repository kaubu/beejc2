#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int starting_time = time(NULL);
    int current_time = starting_time;
    int r = starting_time;
    int new_time;

    do {
        new_time = time(NULL);

        if (current_time == new_time)
        {
            continue;
        }

        current_time = new_time;

        srand(new_time);
        r = rand() % 100;   // Get a random number between 0 and 99
        printf("time: %d | no: %d\n", new_time, r);
    } while (r != 37);

    printf("seconds it took: %d", current_time - starting_time);
}
