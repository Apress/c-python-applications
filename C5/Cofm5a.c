/*     cofm5at.c
     Centre of Mass Calculation.
	Calculates c of m for 2D shape
	enclosed by the curve y = x**2
	and the line y = 4
*/
#define _CRT_SECURE_NO_WARNINGS
#define PY_SSIZE_T_CLEAN	
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include <conio.h>
#include "include/Python.h"



double randfunc();
main()
{

	int  I,outcount;
	float area,total,count;
	FILE *fptr;
char filename[] = "searchpj4.py"; /* python program name */
	FILE* fp2;

FILE *fp3;
	      
	time_t t;

	/*  Local Arrays */
      double x, y,xout[3500],yout[3500],xcofm,ycofm;

	/* file cofm5a.bin contains all points inside the curve */
	/* file cofm5acnt.bin contains total number of points inside the curve and the x and y position of the centre of mass*/

fptr=fopen("cofm5a.bin","w");
fp3=fopen("cofm5acnt.bin","w");

   
   	/* Intializes random number generator */
   	srand((unsigned) time(&t));

	/* clears arrays to zero */
         for( I = 0; I<3500;I++)
	{
		xout[I] = 0.0;
		yout[I] = 0.0;
		
	}
	/* set x and y cofm accumulators to zero */
	xcofm=0.0;
	ycofm=0.0;
	

	total = 0.0;
	count = 0.0;
	outcount = 0;
     for( I = 1;I<= 3500;I++)
     {
		/* get x values between -2 and +2 */
		/* get y values between 0 and +4 */
            x = randfunc()*4.0-2.0;
            y = randfunc()*4.0;
       
		/* If the generated x and y values are above */
		/* the curve y=x^2 then add 1 to count */   
		/* and update the x and y cofm values */
  	   
 	    if(y>pow(x,2))
	    {
		xcofm=xcofm+x;
		ycofm=ycofm+y;
		
		total = total+1;
		outcount = outcount +1;
		xout[outcount] = x;
		yout[outcount] = y;
	    }
	    count = count+1;
		
   	}	
	
	area=(total/count)*16;/* area is part of the square which is 4x4 or 16 sq units */
	printf("total is %f count is %f\n",total,count);

	xcofm=xcofm/total;
	ycofm=ycofm/total;
	
	printf("area is %lf\n",area);
	printf("cofm is %lf,%lf",xcofm,ycofm);
	

	/*  Plot the data */
	
	if(outcount >= 2700)
		outcount = 2700;
	
	fprintf(fp3,"%d\t%lf\t%lf\n",outcount,xcofm,ycofm);
	
 		
     for(I = 1; I<=outcount-1;I++)
		fprintf(fptr,"%lf %lf\n",xout[I],yout[I]);
 	fclose(fptr);
fclose(fp3);

/* Call python program to read the file and produce the diagram showing the position of the centre of mass */

Py_Initialize();

	fp2 = _Py_fopen(filename, "r");
	PyRun_SimpleFile(fp2, filename);

	Py_Finalize();

}

double randfunc()
{
	/* get a random number 0 to 1 */
	double ans;
	

	ans=rand()%1000;
	ans=ans/1000;

 	return ans; /* return the random number to the caller */
      
}

