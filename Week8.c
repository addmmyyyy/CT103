 #include <stdio.h>
#include <math.h>  // Used for rounding later

// Name: Adam McPadden
// ID: 21402142
// Date: 16th of November

float get_volume(int l, int w, int h) {		// Function for getting the volume
	float volume = l * w * h;	// Formula for volume from length, width, and height, assigning the output to the variable volume
	return volume;
}

void get_mass(float v) {		// Function for getting mass
	float mass = v * 1000;		// Formula for mass where v is volume
	printf("The mass of the water is %.2f kg\n", mass);
}

float count_barrels(float v) {		// Function for finding how many barrels can be filled
	float number_of_barrels = (v / 0.48);
	return number_of_barrels;
}

void main() {
	int length = 1;		// Hardcoded three variables
	int width = 4;
	int height = 2;

	float volume = get_volume(length, width, height);	// Initialises a float for volume and then assigns the value of the function to it
	printf("Volume = %.0f metres cubed\n", volume);
	get_mass(volume);	// Runs the above mass function. No print statement is needed as the function itself has print

	float num = count_barrels(volume);	// Initialises a float for number of barrels and then assigns the value from the function
	printf("Barrels = %.f\n", floor(num));	// We print the float after it has been rounded down with the floor() function built in to the math library
}
