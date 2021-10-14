#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/* example of a 2D array test*/
int main()

{
	int arr1[7][8]; /* 2D array */


	int i, j, k, l;

	/* ask the user to enter number of rows and columns to be used */

	printf("enter number of rows and columns (max 7 rows max 8 columns) \n");
	scanf("%d %d", &k, &l); /* store the number of rows and columns */

	/* test if the user has exceeded the limits for rows or columns */

	if (k > 7 || l > 8)
	{
		printf("error - max of 8 for rows or columns\n");

	}

	else
	{
		/* ask the user to enter the data for the arrays */

		printf("enter array\n");
		for (i = 0;i < k;i++)
		{
			for (j = 0;j < l;j++)
			{
				scanf("%d", &arr1[i][j]);
			}
		}

		/* print out the 2D array */


		printf("Your array is \n");
		for (i = 0;i < k;i++)
		{
			for (j = 0;j < l;j++)
			{
				printf("%d ", arr1[i][j]);
			}
			printf("\n");

		}
	}
	
}


