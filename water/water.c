#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get # of minutes user intends to shower for
    printf("minutes: ");
    int m = get_int();
    // get amount of water used per minute
    int t = (m * 192);
    // get # of bottles of water
    int b = (t / 16);
    // return # of bottles used
    printf("bottles: %i\n", b);
}