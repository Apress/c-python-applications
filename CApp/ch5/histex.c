/*Histogram Program*/
#define _CRT_SECURE_NO_WARNINGS
#define PY_SSIZE_T_CLEAN
#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "include/Python.h"

main()
{
	int marks[20];
	
	
	int i;
	

	char filename[] = "pyex3a.py";
	FILE* fp2;

	FILE *fp;
     FILE *fp3;

	fp=fopen("histn.bin","w");
      
	/* User enters 20 marks for a histogram*/
	printf("enter 20 marks (\n");
	

	/* User enters marks*/
	for (i = 0;i < 20;i++)
	{
		printf("marks");
		scanf("%d", &marks[i]);
			
	}

	/* Print the marks entered */
	printf("marks are \n");
	for (i = 0;i < 20;i++)
	{
		printf(" \n");
		printf("%d ", marks[i]);
		fprintf(fp,"%d\n",marks[i]);
	}
	printf(" \n");
		
	
fclose(fp);



Py_Initialize();

	fp2 = _Py_fopen(filename, "r");
	PyRun_SimpleFile(fp2, filename);

	Py_Finalize();
	
}



