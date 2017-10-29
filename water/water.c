#include <stdio.h>
#include <cs50.h>

int main(void) {
    printf("minutes: ");
    int m = get_int();

    int t = (m * 192);

    int b = (t / 16);

    printf("bottles: %i\n", b);

}