#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {
    long long int cardNum;
    long long int cardLength;
    int digit;
    int counter = 0;

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
	    printf("%s\n", "Invalid");
	} else {
	    printf("%s", "Number of digits: ");
    	printf("%d\n", counter);
        //  else loop through card number using modulo and dviding by 10
        while (cardNum) {
            digit = cardNum % 10;
            printf("%d", digit);
            cardNum /= 10;
        }
        printf("\n");
	}
}
