#include <stdio.h>

// Name: Adam McPadden
// Student ID: 21402142
// Date: 9th of November

void main() {
	const float pi = 3.14;	// used a const for pi
	char choice[10];
	int exit_value = 0;
	float height;
	float width;
	float second_width;
	float area;
	float radius;
	char opening_instructions[] = "Area Calculator -Shape Choices are: \n___________________________________________________________\nTriangle, Rectangle, Circle, Trapezium \n___________________________________________________________\n";



	while (exit_value == 0)
	{
		puts(opening_instructions);	//Two lines print out the instructions on how to use the programme

		printf("choice: ");		// Takes a user input of which shape the user wants to find the area of, or whether they want to finish
		gets(choice);

		switch (choice[3])	// Each option has a unique fourth letter so I leveraged this as an efficient method for finding what formula to use
		{
		case 'a':	// case for triAngle
			printf("What is the vertical height of the triangle? ");
			scanf_s("%f", &height);
			printf("What is the width of the base of the triangle? ");
			scanf_s("%f", &width);
			area = width * 0.5 * height;
			printf("Area is %.2f\n", area);
			break;
		case 'c':	// case for cirCle
			printf("What is the radius of the circle? ");
			scanf_s("%f", &radius);
			area = radius * radius * pi;		// <==== Use of const
			printf("Area is %.2f\n", area);
			break;
		case 't':	// case for recTangle
			printf("What is the  height of the rectangle? ");
			scanf_s("%f", &height);
			printf("What is the  width of the rectangle? ");
			scanf_s("%f", &width);
			area = width * height;
			printf("Area is %.2f\n", area);
			break;
		case 'p':	// case for	traPezium
			printf("What is the base of the trapezium? ");
			scanf_s("%f", &width);
			printf("What is the secondary width of the trapezium? ");
			scanf_s("%f", &second_width);
			printf("What is the  height of the trapezium? ");
			scanf_s("%f", &height);
			area = ((width + second_width) * 0.5) * height;
			printf("Area is %.2f\n", area);
			break;
		case 'e':	// case for donE
			exit_value = 1;
			break;
		default:	// if input doesnt satisfy any of the above cases, the programme loops
			break;
		}

		int variable_to_solve_annoying_gets_problem;
		while ((variable_to_solve_annoying_gets_problem = getchar()) != '\n') {}	
		// ^ these lines are necessary to stop the next call to gets() reading \n as an input
	}
}