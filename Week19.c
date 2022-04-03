#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Name: Adam McPadden
// Date: 1/3/2022
// ID: 21402142


// Declaring any variables that need to be global
char dictionary[10000000][50];
char answer[20];
char guessed_letters[10000];
int guess_count = 0;

int fileToArray(char* file) {
	char currentWord[50],character;
	// j is used to track the amount of valid words included in the dictionary
	int j = 0;

	do
	{
		// i is used to iterate over the temporary word string
		int i = 0;
		int valid = 1;

		character = fgetc(file);
		while (character != '\n' && character != EOF) {
			currentWord[i] = character;
			i++;

			// Checks if word has gotten too long
			if (i > 7) {
				valid = 0;
			}
			character = fgetc(file);
		}
		currentWord[i] = '\0';

		// Checks if word is too short
		if (i < 4) {
			valid = 0;
		}

		if (valid == 1) {
			strcpy(dictionary[j], currentWord);
			j++;
		}
	} while (character != EOF);
	printf("Loaded %d suitable words from dictionary\n", (j+1));
	return (j);
}	

char selectWord(int length) {
	// Randomly chooses a word from the array
	int random = rand() % length;
	strcpy(answer,dictionary[random]);
}

int guessLetter() {
	char guess;

	// Prints the guess UI
	printf("\nGuess %d.\n", guess_count + 1);
	updateWord();
	printf("\nGuess a letter : >");

	// Takes in a guess and adds it to the list of guessed letters. The %*c in scanf_s takes the new line input that happens when users click enter.
	scanf_s("%c%*c", &guess);
	guessed_letters[guess_count] = guess;
	guess_count++;

	// Checks if the problem is solved
	int solved = checkAnswer();
	return solved;
}

int updateWord() {
	for (int i = 0; i < strlen(answer); i++) {
		int j = 0;
		int blank = 1;

		// For every letter in the answer, we check if it has been guessed. If it is we print it, if not we print a hyphen.
		while (j < strlen(guessed_letters)+1) {
			if (answer[i] == guessed_letters[j]) {
				printf("%c", answer[i]);
				blank = 0;
				break;
			}
			else {
				j++;
			}
		}
		
		if (blank == 1) {
			printf("-");
		}
	}
}

int checkAnswer() {
	int correct_answer = 1;
	for (int i = 0; i < strlen(answer); i++) {
		int j = 0;
		int blank = 1;

		// Checks if any of the letters in answer haven't been guessed yet. 
		while (j < strlen(guessed_letters) + 1) {
			if (answer[i] == guessed_letters[j]) {
				blank = 0;
				break;
			}
			else {
				j++;
			}
		}
		if (blank == 1) {
			correct_answer = 0;
		}
			
	}

	if (correct_answer == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void main() {

	// Opens the file to be read and checks that it is valid.
	FILE* fptr;
	fopen_s(&fptr, "C:\\Users\\adamm\\Desktop\\College\\CT103\\Assignments\\Assignment18\\Assignment18\\words.txt", "r");
	if (fptr == NULL) {
		printf("File not found");
		return;
	}

	int length = fileToArray(fptr);
	fclose(fptr);

	// Seeds the random generator
	srand(time(NULL));
	selectWord(length);
	
	// Repeats the letter guess until it is solved.
	int solved = 0;
	while (solved == 0) {
		solved = guessLetter();
	}

	printf("\nWell done, that took you %d guesses to find %s!", guess_count, answer);
}