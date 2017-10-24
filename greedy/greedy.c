#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float f;
    //get amount of change needed from user
    do
    {
        printf("How much change do you need? ");
        f = get_float();
    }
    while (f <= 0);

    // convert $(float) amounts to cents(int) while rounding
    int c = roundf(f * 100);

    int q = 0; //quarters used
    int d = 0; //dimes used
    int n = 0; //nickels used
    int r = 0; //remainder

    // how many quaters used
    q = c / 25;
    // get remainder after quarters used
    r = c % 25;
    // using remainder determine how many dimes are needed
    d = r / 10;
    // get remainder after dimes used
    r = r % 10;
    // now same for nickels
    n = r / 5;
    // remainder is used for pennies
    r = r % 5;

    // add the number of quarters, nickels, and dimes plus the remainder for pennies
    int t = q + d + n + r;
    printf("%i\n", t);
}
