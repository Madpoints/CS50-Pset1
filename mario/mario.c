#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get an int between 1 and 23
    int h;
    do
    {
        printf("height: ");
        h = get_int();
    }
    while (h < 0 || h > 23);

    // using loops create the spaces and #
    for (int i = 0; i < h; i++)
    {
        // print spaces
        for (int j = 0; j < h - i - 1; j++)
        {
            printf("%s", " ");
        }
        // print blocks
        for (int k = 0; k < i + 2; k++)
        {
            printf("%s", "#");
        }
        printf("\n");
    }
}