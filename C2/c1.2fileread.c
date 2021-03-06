/* fileread */
/* reads from file */
/* reads and prints sequentially */
/* reads and prints specific records */

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*define the structure for each patientís data */

struct Patient {
	int PatientID;
	char name[13];
	int BloodPressure;
};

int main()
{
	FILE *fp;

	struct Patient s2;


	int numread, i;
	/* Open patients file */

	fp = fopen("patients.bin", "r");
	for (i = 0;i < 17;i++)
	{
		/* Read each patient data from file sequentially */
		fread(&s2, sizeof(s2), 1, fp);
		/* Print patient ID, name and Blood Pressure for each patient */

		printf("\nPatientID : %d", s2.PatientID);
		printf("\n Name : %s", s2.name);
		printf("\nBloodPressure : %d", s2.BloodPressure);


	}

	fclose(fp);


	/* Re-open the patients file */
	fp = fopen("patients.bin", "r");
	for (i = 0;i < 17;i++)
	{
		/* Search the file for patient with ID of 23 */

		fread(&s2, sizeof(s2), 1, fp);
		if (s2.PatientID == 23)
		{
			/* Found the patient. Print their name */
			printf("\nName : %s", s2.name);
			break;
		}
	}
	/* Go back to the beginning of the file */

	fseek(fp, sizeof(s2), SEEK_END);
	rewind(fp);
	/* Find all patients with Blood Pressure reading above 63 */

	for (i = 0;i < 17;i++)
	{
	fread(&s2, sizeof(s2), 1, fp);
		if (s2.BloodPressure > 63)
		{
			/* Print out name of each patient with Blood pressure above 63 */
			printf("\nName : %s", s2.name);

		}
	}
	/* Go back to the beginning of the file */

	
	rewind(fp);

	/* Read and print out the first 3 patients in the file */

	numread = fread(&s2, sizeof(s2), 1, fp);
	if (numread == 1)
	{
		printf("\nPatientID : %d", s2.PatientID);
		printf("\nName : %s", s2.name);
		printf("\nBloodPressure : %d", s2.BloodPressure);
}
	numread = fread(&s2, sizeof(s2), 1, fp);
	if (numread == 1)
	{

		printf("\nPatientID : %d", s2.PatientID);
		printf("\nName : %s", s2.name);
		printf("\nBloodPressure : %d", s2.BloodPressure);
	}
	numread = fread(&s2, sizeof(s2), 1, fp);
	if (numread == 1)
	{
		printf("\nPatientID : %d", s2.PatientID);
		printf("\nName : %s", s2.name);
		printf("\nBloodPressure : %d", s2.BloodPressure);
	}
	/* Close the file */

	fclose(fp);

}
