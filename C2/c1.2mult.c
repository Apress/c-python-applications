#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*  multiply two floating point numbers */

int main()
{
	float this_is_a_number1, this_is_a_number2, total; /* storage areas for the numbers */

	/* ask the user to enter two floating point (decimal) numbers */

	printf("Please enter a number:\n ");
	scanf("%f", &this_is_a_number1); /* read number in */
	printf("You entered %f\n", this_is_a_number1);

	printf("Please enter another number: \n");
	scanf("%f", &this_is_a_number2); /* read number in */
	printf("You entered %f\n", this_is_a_number2);

/* multiply  the two numbers into ‘total’ and display the answer */
	
	total = this_is_a_number1 * this_is_a_number2; /* multiply the numbers */
	printf("product is %f\n", total);

	return 0;
}

