#include <stdio.h>

/*Name: Adam McPadden
  Student ID: 21402142
  Date: 5th October */

void main() {
	float degC;    // Initialises variables for both Celsius and Fahrenheit. Float used instead of Int for extra functionality.
	float degF;

	printf("enter temperature in degrees Fahrenheit: ");

	scanf_s("%f", &degF); // Takes an integer input from the user and maps 				 
						  // it to the variable degF

	degC = ((degF - 32) * (5.0f / 9.0f)); /* converts Fahrenheit to Celsius.
										  5/9 is written using floats to
										  avoid it being read as 0 */

	printf("Degrees Celsius = %f \n", degC);

	if (degC > 32) {             // Nested if else statement that checks if 

		printf("Too hot!");	     // result is high/low enough

	}

	else { 
		
		if (degC < 0) {

			printf("Too cold!");

		}

	}

}