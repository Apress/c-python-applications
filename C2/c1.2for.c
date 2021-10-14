#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/* demonstrate a forloop */
main()

{
	float this_is_a_number, total; /* storage areas for the numbers */
	int i;

	total = 0;

	/* forloop goes round 10 times */
	for (i = 0;i < 10;i++)
	{
		/* ask the user to enter the floating point (decimal) number */

		printf("Please enter a number:\n ");
		scanf("%f", &this_is_a_number); /* read number in */
		total = total + this_is_a_number;

	}
	printf("Total Sum is = %f\n", total);
}

