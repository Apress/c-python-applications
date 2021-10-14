/* csqlfilereadins.c */

/* reads from file */
/* reads and prints sequentially */
/* reads and prints specific records */
#define _CRT_SECURE_NO_WARNINGS




#include <sqlite3.h>
#include <stdio.h>
int main(void) 
{
struct Employee 
{
		int ID;
		char name[13];
		int age;
		char occup[15];
};
FILE *fp;
	struct Employee s2;
	int numread, i;

int count;
	sqlite3 *db;
	char *err_msg = 0;

	int idin,agein;
	char namein[13];
	char occupin[15];

	int rc = sqlite3_open("test.db", &db);/* open the database */
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", 			sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
	}

char *sql = "DROP TABLE IF EXISTS Personnel;"
"CREATE TABLE Personnel(Id INT PRIMARY KEY, Name TEXT, 	Age INT, Occupation);";

rc = sqlite3_exec(db, sql, 0, 0, &err_msg); /*perform the inserts and check if any errors */

	if (rc != SQLITE_OK )
	{
		fprintf(stderr, "SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
		sqlite3_close(db);
		return 1;
	}

count = 0;
	/* Open Employees file */
	fp = fopen("People3.bin", "r");
for (i = 0;i < 11;i++)
	{
		/* Read each Employee data from file sequentially */
		fread(&s2, sizeof(s2), 1, fp);
count++;
	/* user is asked to enter the fields for this row */
/*printf("enter  id \n");*/ /* ID */
	/*scanf("%d", &idin);*/
idin = s2.ID;
	/*printf("enter name id \n");*/ /* NAME */ 
	/*scanf("%s", &namein);*/
strcpy(namein, s2.name);
	/*printf("enter age \n");*/ /* AGE */
	/*scanf("%d", &agein);*/
agein = s2.age;
	/*printf("enter occupation \n");*/ /* OCCUPATION */
	/*scanf("%s", &occupin);*/
strcpy(occupin, s2.occup);

printf("id is %d:name is %s:age is %d:occupation is %s\n",idin, namein, agein, occupin);


	/* The INSERT command string is set up */
	char str1[200] = "INSERT INTO Personnel VALUES( ";
	char str2[] = " ); ";
	char str3[2]; 
	char str4[6];
	char str5[] = ", "; 
	char str6[] = "'";

	sprintf(str4, "%d", idin);
	sprintf(str3, "%d", agein);

	strcat(str1,str4); /* ID */
	strcat(str1,str5); /* comma */
	strcat(str1,str6); /* quote */
	strcat(str1,namein); /* name */
	strcat(str1,str6); /* quote */
	strcat(str1,str5); /* comma */
	strcat(str1,str3); /* age */
	strcat(str1,str5); /* comma */
	strcat(str1,str6); /* quote */
	strcat(str1,occupin); /* occupation */
	strcat(str1,str6); /* quote */
	strcat(str1,str2); /* close bracket and semi-colon */

	printf(str1); /* completed string */
	printf("\n"); 

/* so, for ID=12, name=Pickford, age=48 and occupation = Welder */
/* our completed string will be :- */
/* INSERT INTO Personnel VALUES( 12, 'Pickford', 48, 'Welder' ); */


	char *sql = str1;

	rc = sqlite3_exec(db, sql, 0, 0, &err_msg);/* execute the insert */
	if (rc != SQLITE_OK )
	{
		fprintf(stderr, "SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
		sqlite3_close(db);
		return 1;
	}
}
printf("count is %d\n",count);
	sqlite3_close(db); /* close the database connection */

fclose(fp);
	return 0;
}





























