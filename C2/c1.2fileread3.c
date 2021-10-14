/* fileread */
/* reads from file */
/* reads and prints sequentially */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*define the structure for each student’s data */

struct student {
	int studentID;
	char name[13];
	int marks;
};

int main()
{
	FILE *fp;

	struct student s2;


	int numread, i;
	/* Open students file */

	fp = fopen("students.bin", "r");
printf("\nAll students\n");
	for (i = 0;i < 15;i++)
	{
		/* Read each student data from file sequentially */
		fread(&s2, sizeof(s2), 1, fp);
		/* Print student ID, name and Blood Pressure for each student */

		printf("\nstudentID : %d", s2.studentID);
		printf("\n Name : %s", s2.name);
		printf("\nmarks : %d", s2.marks);


	}

	fclose(fp);

}
