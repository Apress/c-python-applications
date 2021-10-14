#include <sqlite3.h>
#include <stdio.h>
int main(void)
{
	sqlite3 *db;
	char *err_msg = 0;
	sqlite3_stmt *res;
	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", 			sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
	}
	int idin;
	printf("enter  id to be deleted\n");
	scanf("%d", &idin);

	char str1[200] = "DELETE FROM Personnel WHERE id =  ";
	char str2[] = " ); ";
	char str3[2]; 
	char str4[6];
	char str5[] = ", "; 
	char str6[] = "'";

	sprintf(str4, "%d", idin);
	

	strcat(str1,str4);
	printf(str1);
	printf("\n");


	char *sql = str1;



	rc = sqlite3_exec(db, sql, 0, 0, &err_msg); /* perform the insert */
	if (rc != SQLITE_OK )
	{
		fprintf(stderr, "SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
		sqlite3_close(db);
		return 1;
	}
	sqlite3_close(db); /* close the database connection */
	return 0;

}