#include <stdio.h>
#include <cs50.h>
#include <math.h>

int getLastInt(long long int num);

char *cardType(int num);

int main(void)
{
    long long int cardNum;
    long long int cardLength;
    int counter = 0;
    int evenSum = 0;
    int oddSum = 0;

    //get the card number from the user
    do
    {
        printf("What is your credit card number? (Totally not shady):  ");
        cardNum = get_long();
    }
    while (cardNum <= 0);

    // set cardNum to cardLength
    cardLength = cardNum;

    // loop through and count the # of digits of cardLength
    do
    {
        cardLength /= 10;
        counter++;
    }
    while (cardLength);

    cardLength = counter;

    // check cardLength
    if (cardLength < 13 || cardLength > 16)
    {
        printf("%s\n", "INVALID");

    }
    else
    {
        // array to store card numbers
        int *cardArray = malloc(10 * sizeof(cardLength));
        // store cardNum digits in cardArray
        for (int i = 0; i < cardLength; i++)
        {
            if (cardNum)
            {
                cardArray[i] = getLastInt(cardNum);
                cardNum /= 10;
            }
        }
        // use Luhn’s algorithm to get the checksum of the credit card number
        for (int i = 0; i < cardLength; i++)
        {
            if (i % 2 != 0)
            {
                if (cardArray[i] * 2 >= 10)
                {
                    oddSum += getLastInt(cardArray[i] * 2);
                    oddSum += 1;
                }
                else
                {
                    oddSum += cardArray[i] * 2;
                }
            }
            else
            {
                evenSum += cardArray[i];
            }
        }

        int total = evenSum + oddSum;

        // check card number validity and maker if valid
        if (getLastInt(total) == 0)
        {
            printf("%s", cardType(cardArray[cardLength - 1]));
        }
        else
        {
            printf("%s\n", "INVALID");
        }
    }
}

// returns the last digit of a number
int getLastInt(long long int num)
{

    return num % 10;

}

// returns card type
char *cardType(int num)
{
    if (num == 4)
    {
        return "VISA\n";
    }
    else if (num == 5)
    {
        return "MASTERCARD\n";
    }
    else if (num == 3)
    {
        return "AMEX\n";
    }
    else
    {
        return "VALID BUT NOT FOUND\n";
    }
}