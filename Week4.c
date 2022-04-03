
#include <stdio.h>

// Name: Adam McPadden
// ID: 21402142
// Date: 19/10/2021

int main()
{
    int inputted_age = 0;
    int i = 0;
    int stored_minimum = 100;       // initialised with 100 to ensure that the first correct input will be less than
    int stored_maximum = 0;     // initialised with 0 to ensure that the first input will be more than
    float total_age = 0;
    float average_age;

    printf("When you have finished entering ages, input a negative number to see results!\n");

    while (inputted_age >= 0) {
        
        printf("Input age of child: ");
        scanf_s("%d", &inputted_age);

        if (inputted_age < 18) {        // checks if age counts as a child

            if (inputted_age < 0) {     // breaks loop if age less than 0 is input
                break;
            }

            if (inputted_age > stored_maximum) {        //  keeps track of the largest age input
                stored_maximum = inputted_age;
            }

            if (stored_minimum > inputted_age) {        //  keeps track of the smallest age input
                stored_minimum = inputted_age;
            }

            total_age = total_age + inputted_age;       //  keeps total of ages input
            i++;        //  keeps track of number of children
        }

        else {
            printf("Not a child\n");
        }

    } 

    average_age = total_age / i;

    printf("There are %d children \n", i);

    if (i > 0) {                                            //  only outputs results if age given
        printf("The oldest child's age is %d \n", stored_maximum);
        printf("The youngest child's age is %d \n", stored_minimum);
        printf("The average age is %g", average_age);       //  %g used instead of %f in order to remove trailing zeroes
    }
}

