#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

/*appends a record to the file*/
/* then prints the whole file */

/*define the structure for each student’s data */

struct student {
	int studentID;
	char name[13];
	int marks;
};

int main()
{
	int i, numread;
	FILE *fp;
	struct student s1;
	struct student s2;

	/* Preset the data for the student */

	struct student s25 = { 25,"Foster      ",82 };
	

	

	/* Open the students file */
	fp = fopen("students.bin", "a"); /* "a" means append */

	/* Write details of the student to file*/
	/* From the structure defined above */

	
	fwrite(&s25, sizeof(s1), 1, fp);

	

	/* Close the file */

	fclose(fp);

	/* Reopen the file */

	fopen("students.bin", "r");

	/* Read and print out all of the records on the file */

	for (i = 0;i < 16;i++)
	{

		numread = fread(&s2, sizeof(s2), 1, fp);/* read into structure s2 */

		if (numread == 1)
		{
			
		/* reference elements of structure by s2.studentID etc */
			printf("\nstudentID : %d", s2.studentID);
			printf("\nName : %s", s2.name);
			printf("\nmarks : %d", s2.marks);
		}
		else {
			/* If an error occurred on read then print out message */

			if (feof(fp))

				printf("Error reading students.bin : unexpected end of file fp is %p\n", fp);

			else if (ferror(fp))
			{
				perror("Error reading students.bin");
			}
		}




	}
	/* Close the file */

	fclose(fp);





}

