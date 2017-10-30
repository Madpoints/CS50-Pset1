#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    long long int cardNum;
    long long int cardLength;
    int counter = 0;
    int evenSum = 0;
    int oddSum = 0;

    //get the card number from the user
    do {
        printf("What is your credit card number? (Totally not shady):  ");
        cardNum = get_long();
    } while (cardNum <= 0);

    // set cardNum to cardLength
    cardLength = cardNum;

    // loop through and count the # of digits of cardLength
    do {
    	cardLength /= 10;
    	counter++;
	} while (cardLength);

    // if the count is less than 13
	if (counter < 13 || counter > 16) {
	    printf("%s\n", "INVALID");
	} else {
	    int *cardArray = malloc(10 * sizeof(counter));
	   // printf("%s", "Number of digits: ");
    // 	printf("%d\n", counter);
	    counter = 0;
        //  else loop through card number using modulo and dviding by 10
        while (cardNum) {
            cardArray[counter] = cardNum % 10;
            // printf("%d", cardArray[counter]);
            counter++;
            cardNum /= 10;
        }

        for (counter = 0; counter < sizeof(cardArray) * 2; counter++) {
            // printf("%d", cardArray[counter]);
            if (counter % 2 != 0) {
                if (cardArray[counter] * 2 >= 10) {
                    oddSum += cardArray[counter] * 2 % 10;
                    oddSum += 1;
                } else {
                    oddSum += cardArray[counter] * 2;
                }
            } else {
                evenSum += cardArray[counter];
            }
        }
        // printf("\n");

        int total = evenSum + oddSum;

        if (total % 10 == 0) {
            if (cardArray[sizeof(cardArray) * 2 - 1] == 4) {
                printf("%s\n", "VISA");
            } else if (cardArray[sizeof(cardArray) * 2 - 1] == 5) {
                printf("%s\n", "MASTERCARD");
            } else if (cardArray[sizeof(cardArray) * 2 - 2] == 3) {
                printf("%s\n", "AMEX");
            }
        } else {
            printf("%s\n", "INVALID");
        }
	}
}
