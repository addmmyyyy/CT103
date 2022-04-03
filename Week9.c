/*
Name: Adam McPadden
Student ID: 21402142
Date: 23rd of November
*/

#include <stdio.h>
#include <math.h>

const float dayRate = 23.9;		// Declare constants
const float nightRate = 12.6;

float getTime() {
	float hour;	
	float minute;

	printf("Please enter the current hour: ");	//	This code block takes the usesr input for the hour.
	scanf_s("%f",&hour);
	if (hour > 23) {	// These two if statements reset to the maximum if input is above the maximum, or to the minimum if input is below the minimum
		hour = 23;
	}
	if (hour < 0) {
		hour = 0;
	}

	printf("Please enter the current minute: "); //	This code block takes the usesr input for the minute.
	scanf_s("%f", &minute);
	if (minute > 59) {	// These two if statements reset to the maximum if input is above the maximum, or to the minimum if input is below the minimum
		minute = 59;
	}
	if (minute < 0) {
		minute = 0;
	}
	minute = (minute / 60);		// This gets the minute amount as a fraction of a full hour

	float time = minute + hour;	// Gets combined hour and minute time
	return time;
}

float roundTime(float time) {
	time = ceil(time);	// Rounds any floats (with non-zero values after the decimal point) to the next largest value
	if (time == 24) {	// Necessary to fix the issue where values are rounded to 24:00; which would be 0:00 on a 24-hour clock
		time = 0.00;
	}
	return time;
}

float choosePrice(float time) {
	float rate;	
	rate = (time < 8) ? (nightRate) : (dayRate);	// This conditional operator chooses which rate to display.
	return rate;
}

void printFinal(float roundedTime,float time, float price) {
	printf("Time = %.2f.\n", time);
	printf("Time = %.2f.\n", roundedTime);
	printf("Electricity price at time %.2f is %.1f c/kWh.", roundedTime, price);
}

void main() {
	float time = getTime();
	float roundedTime = roundTime(time);
	float rate = choosePrice(roundedTime);
	printFinal(roundedTime,time, rate);
}