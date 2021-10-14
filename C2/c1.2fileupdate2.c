/* fileupdate */
/* reads and prints sequentially */
/* reads, updates and prints specific records */

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
	long int minusone = -1;
	struct student s2;


	int numread, i;
	/* Open students file */

	fp = fopen("students.bin", "r");
	printf("\nAll students\n");
	for (i = 0;i < 15;i++)
	{
		/* Read each student data from file sequentially */
		fread(&s2, sizeof(s2), 1, fp);
		/* Print student ID, name and marks for each student */

		printf("\nstudentID : %d", s2.studentID);
		printf("\n Name : %s", s2.name);
		printf("\nmarks : %d", s2.marks);


	}

	fclose(fp);


	/* Re-open the students file */
	fp = fopen("students.bin", "r+");  /* r+ is for update */
	printf("\nStudent ID=23\n");

	for (i = 0;i < 15;i++)
	{
		/* Search the file for student with ID of 23 */

		fread(&s2, sizeof(s2), 1, fp);
		if (s2.studentID == 23)
		{
			/* Found the student. */
			/* update their marks */
			/* Print their updated details */

			s2.marks = s2.marks + 10;
			printf("\nName : %s", s2.name);
			printf("\nmarks : %d", s2.marks);
			fseek(fp,minusone*sizeof(s2),SEEK_CUR);
			fwrite(&s2,sizeof(s2),1,fp);
			break;
		}
	}
	/* Go back to the beginning of the file */

	fseek(fp, sizeof(s2), SEEK_END);
	rewind(fp);
	printf("\updated file\n");

	/* read and display the updated file*/

	for (i = 0;i < 15;i++)
	{
		fread(&s2, sizeof(s2), 1, fp);
		printf("\nName : %s", s2.name);
		printf("\nmarks : %d", s2.marks);
	
	}
	
	fclose(fp);

}

