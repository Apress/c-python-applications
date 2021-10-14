/* filereadexr */
/* reads from file */
/* reads and prints sequentially */
/* reads and prints specific records */
/* Does not use seek */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

struct Patient {
	int PatientID;
	char name[13];
	int BloodPressure;
	char allergies;
	char leukaemia;
	char anaemia;
	char asthma;
	char epilepsy;
	char famepil;
};

int main()
{
	FILE *fp;

	struct Patient s1;
	

	struct Patient s2;
struct Patient s10 = { 10,"Brown       ",50,'y','n','n','y','n','y' };
	struct Patient s11 = { 11,"Jones       ",51,'y','y','n','y','y','n' };
	struct Patient s12 = { 12,"White       ",52,'y','n','y','y','n','n' };
	struct Patient s13 = { 13,"Green       ",53,'y','n','y','y','n','n' };
	struct Patient s14 = { 14,"Smith       ",54,'y','y','n','y','y','n' };
	struct Patient s15 = { 15,"Black       ",55,'y','n','n','y','n','n' };
	struct Patient s16 = { 16,"Allen       ",56,'y','n','n','y','n','y' };
	struct Patient s17 = { 17,"Stone       ",57,'y','n','n','y','y','n' };
	struct Patient s18 = { 18,"Evans       ",58,'y','y','n','y','n','n' };
	struct Patient s19 = { 19,"Royle       ",59,'y','n','y','y','n','n' };
	struct Patient s20 = { 20,"Stone       ",60,'y','y','n','y','n','n' };
	struct Patient s21 = { 21,"Weeks       ",61,'y','n','n','y','y','y' };
	struct Patient s22 = { 22,"Owens       ",62,'y','n','n','y','y','y' };
	struct Patient s23 = { 23,"Power       ",63,'y','n','n','y','n','n' };
	struct Patient s24 = { 24,"Bloom       ",63,'y','n','y','y','n','n' };
	struct Patient s28 = { 28,"Haver       ",68,'y','y','n','y','n','n' };
	struct Patient s29 = { 29,"James       ",69,'y','y','n','y','n','n' };



	int numread, i;
	double casthepi;
	double percent;

fp = fopen("patientex.bin", "w");

	/* Write details of each patient to file*/
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

	fwrite(&s28, sizeof(s1), 1, fp);
	fwrite(&s29, sizeof(s1), 1, fp);

	/* Close the file */

	fclose(fp);

	/* Reopen the file */



	/* Open patients file */

	fp = fopen("patientex.bin", "r");
	for (i = 0;i < 17;i++)
	{
		/* Read each patient data from file sequentially */
		fread(&s2, sizeof(s2), 1, fp);
		/* Print patient ID, name and Blood Pressure for each patient */

		printf("\nPatientID : %d", s2.PatientID);
		printf("\n Name : %s", s2.name);
		printf("\nBloodPressure : %d", s2.BloodPressure);
		printf("\nAllergies %c leukaemia %c anaemia %c", s2.allergies, s2.leukaemia, s2.anaemia);
		printf("\nAsthma %c epilepsy %c famely epilepsy %c", s2.asthma, s2.epilepsy, s2.famepil);


	}

	fclose(fp);


	/* Re-open the patients file */

	fp = fopen("patientex.bin", "r");
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
	/* Re-open the patients file */
	casthepi = 0;
	fp = fopen("patientex.bin", "r");
	for (i = 0;i < 17;i++)
	{
		/* Search the file for link between asthma and epilepsy */

		fread(&s2, sizeof(s2), 1, fp);
		if (s2.epilepsy == 'y' && s2.asthma == 'y')
		{
			casthepi = casthepi + 1.0;
			/* Found the patient. Print their name */
			printf("\nLink between asthma and epilepsy");
			printf("\nName : %s", s2.name);

		}
	}
	percent = (casthepi / 17.0)*100.0;
	printf("\npercent asthma & epilepsy : %f", percent);
	fclose(fp);

}

