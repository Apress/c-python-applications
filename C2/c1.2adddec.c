#include <stdio.h>

/*  Add two floating point numbers */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	float this_is_a_number1, this_is_a_number2, total; /* storage areas for the numbers */

	/* ask the user to enter two floating point (decimal) numbers */


	printf("Please enter a number:\n ");
	scanf("%f", &this_is_a_number1); /* read decimal number in */
	printf("You entered %f\n", this_is_a_number1);

	printf("Please enter another number: \n");
	scanf("%f", &this_is_a_number2); /* read decimal number in */
	printf("You entered %f\n", this_is_a_number2);

	/* add the two numbers into �total� and display the answer */

	total = this_is_a_number1 + this_is_a_number2; /* add the numbers */
	printf("total is %f\n", total);

	return 0;
}
