// Name: Adam McPadden
// ID: 21402142
// Date: 26th of October


#include <stdio.h>
void main() {
	float sales[1000];		// Array size set to 1000 to minimise chance of too many days being input
	int i;
	int additional_times;
	float total = 0;
	float average;

	for (i = 1; i < 8; i++) {			// Simple for loop that takes input with scanf_s and then adds the input to the array 'sales'.
		printf("Enter sales for day %d : ", i);		// i is iterated to track day and where to put input in array.
		scanf_s("%f", &sales[i]);
		total = total + sales[i];
	}

	average = total / 7;	// Arithmetic to obtain average

	printf("\nTotal sales for period is %.2f Euros", total);
	printf("\nAverage sales for period is %.2f Euros\n", average);
	
	printf("\nHow many additional days of sales do you want to include? ");		// Takes an input that determines how many additional days of sales to read
	scanf_s("%d", &additional_times);

	for (i = 8; i < (8 + additional_times); i++) {		// Same function as previous for loop
		printf("Enter sales for day %d : ", i);
		scanf_s("%f", &sales[i]);
		total = total + sales[i];
	}
	
	for (i = 1; i < (8 + additional_times); i++) {		// Prints out every days sales
		printf("The sales for day %d is %.2f Euros\n", i, sales[i]);
	}

	average = total / (7+additional_times);
	printf("\nUpdated total sales for period is %.2f Euros", total);
	printf("\nUpdated average sales for period is %.2f Euros", average);
}
