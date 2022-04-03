// Name: Adam McPadden
// ID: 21402142
// Date: 18th January

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int trueX, trueY;

void randomSearch(int gridSize) {
	int guessX = 10, guessY = 10, guesses = 0;	// guesses are initialised as 10 so the while loop will happen at least once

	while (guessX != trueX || guessY != trueY) {
		// Guesses are randomly generated and a counter increases by one, until guesses are correct
		guessX = (rand() % gridSize);
		guessY = (rand() % gridSize);
		guesses += 1;
	}
	printf("\n----------- Random Search ----------- \n Ship found after %d locations \n Ship co-ordinates - x : %d, y : %d.", guesses, guessX, guessY);
}

void gridSearch(int gridSize, int attemptCount) {
	int guessX, guessY;
	int shipFound = 0;


	guessX = attemptCount % gridSize;	// Modulo is used so after the attempt count goes higher than the number of squares on the grid, it 'loops back' to x = 0
	guessY = floor(attemptCount / gridSize); // This allows the Y guess to go up after all 10 or 2 squares in a row are checked, moving to the next row.

	if (guessX != trueX || guessY != trueY) {
		attemptCount += 1;
		gridSearch(gridSize, attemptCount); // The function is repeated whenever it fails to find the ship
	}
	else {
		printf("\n----------- Grid Search ----------- \n Ship found after %d locations \n Ship co-ordinates - x : %d, y : %d.", attemptCount, guessX, guessY);
	}
}

void main() {
	int gridSize = 10;

	// Randomly generates the ship's co-ordinates
	srand(time(NULL));
	trueX = (rand() % gridSize);
	trueY = (rand() % gridSize);

	randomSearch(gridSize);
	gridSearch(gridSize, 0);

	// Regenerates co-ords for the 2*2 grid
	printf("\n=========== New Grid ===========");
	gridSize = 2;
	trueX = (rand() % gridSize);
	trueY = (rand() % gridSize);

	randomSearch(gridSize);
	gridSearch(gridSize, 0);
}