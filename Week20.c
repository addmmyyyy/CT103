#include <stdio.h>
#include <ctype.h>

//	Name: Adam McPadden
//	Date: 09/03/2022
//	Student ID: 21402142

// These variables as set as global for ease of use
int sentences_amount = 0;
int words_amount = 0;
int syllables_amount = 0;

char file_as_string[100000];

// A function to count syllables
void syllableCount(char word[]) {
	int currently_alpha = 0;
	int temp_syllables = 0;

	// E is treated differently due to the case where it's the last letter in a word.
	char vowel[] = { "aiouy" };
	char e[] = {"Ee"};

	// Iterates over each letter in the word
	for (int i = 0; i < strlen(word); i++) {

		// If and only if we move from a non-vowel to a valid set of vowels (i.e. not a closing e), do we add to the number of syllables.
		if ((strchr(vowel, tolower(word[i])) != NULL) || (strchr(e,word[i]) && (i+1) != strlen(word))) {
			if (currently_alpha == 0) {
				currently_alpha = 1;
				syllables_amount++;
				temp_syllables++;
			}
		}
		else {
			currently_alpha = 0;
		}

	}
	if (temp_syllables < 1) {
		temp_syllables++;
		syllables_amount++;
	}
	printf("\n%s\t%d", word, temp_syllables);
}

void fileToString() {
	// Opens file and adds the contnet to file_as_string
	FILE* fptr;
	fopen_s(&fptr, "C:\\Users\\adamm\\Desktop\\College\\CT103\\Assignments\\Assignment20\\Assignment20_AdamMcPadden_21402142\\TestFile.txt", "r");
	
	if (fptr == NULL) {
		printf("failed to open file");
		return;
	}

	char c;
	int i = 0;
	c = fgetc(fptr);
	while (c != EOF) {
		file_as_string[i] = c;
		i++;
		c = fgetc(fptr);
	}
}

void wordCount(char sentence[]) {
	int j=0;
	char word[50] = "";
	char alphabet[] = {"qwertyuiopasdfghjklzxcvbnm1234567890'" };

	// Iterates over the sentence
	for (int i = 0; i < strlen(sentence); i++) {
		
		// While we're reading alphabetical characters, we add those characters to a string "word"
		if (strchr(alphabet, tolower(sentence[i])) != NULL) {
			word[j] = sentence[i];
			j++;
		}

		// When we begin to read whitespace, we have a full word - so we count its sylables, add to the word count, and reset the word string
		else {
			if (strlen(word) > 0) {
				syllableCount(word);
				words_amount++;
				printf("\t%d", words_amount);
				j = 0;
				memset(word, 0, sizeof(word));
			}
		}
	}
	syllableCount(word);
	words_amount++;
	printf("\t%d", words_amount);
}

void sentenceCount() {
	fileToString();
	
	// Deliminators for sentences
	char delims[] = {"?!.;;"};

	// Using strtok we can easily split the text into sentences
	char* token;
	token = strtok(file_as_string, delims);
	while (token != NULL) {
		wordCount(token);
		sentences_amount++;
		token = strtok(NULL, delims);
	}
}

void main() {
	sentenceCount();

	// Calculates and prints the index
	float flesch_index = 206.835 - 84.6 * (syllables_amount / words_amount) - 1.015 * (words_amount / sentences_amount);
	printf("\nSentences: %d,   Words: %d    Syllables: %d", sentences_amount, words_amount, syllables_amount);
	printf("\n%f", flesch_index);
}