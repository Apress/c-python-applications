#include <sqlite3.h>
#include <stdio.h>
int main(void)
{
	sqlite3 *db;
	char *err_msg = 0;

	int idin,agein,rowsin,i;
	char namein[13];
	char occupin[15];

	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", 			sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
	}

	printf("enter the number of rows you wish to insert (max 	10) \n");
	scanf("%d", &rowsin);
	for(i=0; i<rowsin; i++)
	{


		printf("enter  id \n");
		scanf("%d", &idin);
		printf("enter name id \n");
		scanf("%s", &namein);
		printf("enter age \n");
		scanf("%d", &agein);
		printf("enter occupation \n");
		scanf("%s", &occupin);

		char str1[200] = "INSERT INTO Personnel VALUES( ";
		char str2[] = " ); ";
		char str3[2]; 
		char str4[6];
		char str5[] = ", "; 
		char str6[] = "'";

		sprintf(str4, "%d", idin);
		sprintf(str3, "%d", agein);

		strcat(str1,str4);
		strcat(str1,str5);
		strcat(str1,str6);
		strcat(str1,namein);
		strcat(str1,str6);
		strcat(str1,str5);
		strcat(str1,str3);
		strcat(str1,str5);
		strcat(str1,str6);
		strcat(str1,occupin);
		strcat(str1,str6);
		strcat(str1,str2);

		printf(str1);
		printf("\n");

	
		char *sql = str1;

		rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
		if (rc != SQLITE_OK ) 
		{
			fprintf(stderr, "SQL error: %s\n", err_msg);
			sqlite3_free(err_msg);
			sqlite3_close(db);
			return 1;
		}
	}
	sqlite3_close(db);
	return 0;
}
