#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int main()
{
	int i, testvalue;
	int x1,x2,x3,x4,x5,x6;

	
printf("Please enter a number:\n ");
	scanf("%d", &testvalue); /* read number in */

	x1 = x2 = x3 = x4 = x5 = x6 = 0;
	a:
		x1 = 1;

	b:
		x2 = 1;
		if(testvalue == 2)
			goto f;
	c:
		x3 = 1;
	d:
		x4 = 1;
	e:
		x5 = 1;
	f:
		x6 = 1;

	
	
	printf("x1 = %d, x2 = %d, x3 = %d,x4= %d, x5 = %d,x6 = %d,   \n",x1,x2,x3,x4,x5,x6);
}
