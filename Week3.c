// Name: Adam McPadden
// Student ID: 21402142
// Date: 12/10/2021


#include <stdio.h>
void main() {
	float tds_day_one = 0.0;           // Initisalising variables used. Floats used to handle cents.
	float tds_day_two = 0.0;
	float tds_day_three = 0.0;
	float tds_day_four = 0.0;
	float total, average;
	float average_spend;


	printf("Enter total sales for day one (in Euros):");	// Four pairs of printf() and scanf_s() functions to find
	scanf_s("%f", &tds_day_one);							// sales for each day

	printf("Enter total sales for day two (in Euros):");
	scanf_s("%f", &tds_day_two);

	printf("Enter total sales for day three (in Euros):");
	scanf_s("%f", &tds_day_three);

	printf("Enter total sales for day four (in Euros):");
	scanf_s("%f", &tds_day_four);

	total = tds_day_one + tds_day_four + tds_day_three + tds_day_two;	// Arithmetic to get average of four days
	average = total / 4;

	printf("Average daily sales during period is %.2f Euros \n", average);

	if (average > 15000) {				// Nested if else statement to determine if prices are high,low or normal
		printf("Sales are high! \n");
	}
	else if (average < 10000) {
		printf("Sales are low! \n");
	}
	else {
		printf("Sales are normal! \n");
	}
	if (average >= 5) {					// Stops average from being printed if less than one cent
		average_spend = average / 500; //Calculates average spend and then prints it to 2 decimals
		printf("Average amount spent during period is %.2f Euros", average_spend);
	}
}