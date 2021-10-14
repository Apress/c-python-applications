/* filewrite */
/* creates file */
/* Finds writes records to the file*/
/* prints out the records sequentially */


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
	int i, numread;
	FILE *fp;
	struct student s1;
	struct student s2;
/* Preset the data for each student */

	struct student s10 = { 10,"Coster      ",15 };
	struct student s11 = { 11,"Harris      ",20 };
	struct student s12 = { 12,"Frazer      ",25 };
	struct student s13 = { 13,"Kirrane     ",30 };
	struct student s14 = { 14,"Marley      ",35 };
	struct student s15 = { 15,"OBrien      ",40 };
	struct student s16 = { 16,"Brown       ",45 };
	struct student s17 = { 17,"Tomlinson   ",50 };
	struct student s18 = { 18,"Mulcahy     ",55 };
	struct student s19 = { 19,"Coyle       ",60 };
	struct student s20 = { 20,"Baxter      ",65 };
	struct student s21 = { 21,"Weeks       ",70 };
	struct student s22 = { 22,"Owens       ",75 };
	struct student s23 = { 23,"Cannon      ",80 };
	struct student s24 = { 24,"Parker      ",85 };

	

	/* Open the students file */
	fp = fopen("students.bin", "w");

	/* Write details of each student to file*/
	/* From the structures defined above */

	fwrite(&s10, sizeof(s1), 1, fp);
	fwrite(&s11, sizeof(s1), 1, fp);
	fwrite(&s12, sizeof(s1), 1, fp);
	fwrite(&s13, sizeof(s1), 1, fp);
	fwrite(&s14, sizeof(s1), 1, fp);
	fwrite(&s15, sizeof(s1), 1, fp);
	fwrite(&s16, sizeof(s1), 1, fp);
	fwrite(&s17, sizeof(s1), 1, fp);
	fwrite(&s18, sizeof(s1), 1, fp);
	fwrite(&s19, sizeof(s1), 1, fp);
	fwrite(&s20, sizeof(s1), 1, fp);
	fwrite(&s21, sizeof(s1), 1, fp);
	fwrite(&s22, sizeof(s1), 1, fp);
	fwrite(&s23, sizeof(s1), 1, fp);
	fwrite(&s24, sizeof(s1), 1, fp);

	

	/* Close the file */

	fclose(fp);

	/* Reopen the file */

	fopen("students.bin", "r");

	/* Read and print out all of the records on the file */

	for (i = 0;i < 15;i++)
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
