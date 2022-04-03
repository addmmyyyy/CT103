// Name: Adam McPadden
// ID: 21402142
// Date: 30th November

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Finds the number of digits in a number by checking how many times it can be divided by ten before it is less than 1
int digitCount(int input) {
	int i = 0;
	do {
		input /= 10;
		i++;
	} while (input > 0);
	return i;
}

// Sets the passcode to a random integer less than or equal to N
int setPasscode(int N) {
	N += 1;
	int correctPasscode = (rand() % N);
	printf("%d\n", correctPasscode);
	return correctPasscode;
}


void randomPasscodeSearch(int correctPasscode, int maxPasscode) {
	int randomGuess = -1;
	int i = 0;
	maxPasscode += 1;

	// Generates random guesses until the guess is the correct passcode
	while (randomGuess != correctPasscode) {
		i += 1;
		randomGuess = (rand() % maxPasscode);
	}

	printf("Random Search. Password = %d - Found after %d attempts\n", randomGuess, i);;
}

void orderedPasscodeSearch(int correctPasscode, int digitLength) {
	// Iterates over every number starting from 0 until the number is the correct passcode; at which point it prints and then breaks
	for (int i = 0; i < pow(10,digitLength); i++) {
		if (i == correctPasscode) {
			i++;
			printf("Ordered Search. Password = %d - Found after %d attempts\n", correctPasscode, i);
			break;
		}		
	}

}


void main() {
	int N;

	srand(time(NULL)); // Seeds with current time in order to create pseudo-random passcodes

	for (int i = 0; i < 4; i++) {
		printf("Maximum passcode = ");	// Takes user input for N
		scanf_s("%d", &N);

		int correctPasscode = setPasscode(N);	// Creates the passcode to test searches against

		randomPasscodeSearch(correctPasscode, N);

		int digitLength = digitCount(N);	// Finds the digital length for the ordered search
		orderedPasscodeSearch(correctPasscode, digitLength);
	}

	int finalPasscode;
	printf("Final Passcode: ");
	scanf_s("%d", &finalPasscode);

	randomPasscodeSearch(finalPasscode, finalPasscode);

	int digitLength = digitCount(finalPasscode);
	orderedPasscodeSearch(finalPasscode, digitLength);
}