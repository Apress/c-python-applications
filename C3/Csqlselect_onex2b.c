#include <sqlite3.h>
#include <stdio.h>

int callback(void *, int, char **, char **);

int main(void) 
{
sqlite3 *db;
char *err_msg = 0;
const char* data = "Callback function called";
int tot0 = 0;
int tot;
int sqlite3_changes(sqlite3*);
int rc = sqlite3_open("test.db", &db); /* open the database */
if (rc != SQLITE_OK) 
{
		fprintf(stderr, "Cannot open database: %s\n",
		sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
}
int idin,idnew;


printf("enter current ID \n");
scanf("%d", &idin);

char str1[] = "SELECT name, age, occupation FROM Personnel WHERE id = ";

char str4[10]; 
char str5[] = ";";



printf("idin = %d\n", idin);
sprintf(str4, "%d", idin); /* store the entered id in str4 */

strcat(str1,str4); /* concatenate the ID into str1 above */
strcat(str1,str5); /* semi-colon */

printf("select statement is \n"); /* output string to user */
printf(str1);
printf("\n");

/* so, for ID=12 */
/* our completed string will be :- */

/* SELECT name, age, occupation FROM Personnel WHERE id = 12; */

char *sql = str1;

/* rc = sqlite3_exec(db, sql, callback, 0, &err_msg);*/
rc = sqlite3_exec(db, sql, callback, (void*)data, &err_msg);
printf("rc = %d\n",rc);
/*printf(callback);*/

if (rc != SQLITE_OK ) 
{
		fprintf(stderr, "Failed to select data\n");
		fprintf(stderr, "SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
		sqlite3_close(db);
		return 1;
}

    tot = sqlite3_changes(db);
    printf("tot = %d\n",tot);

    if (tot == tot0)
{
        printf("Table not updated");
}




sqlite3_close(db);
 
return 0; /* close the database connection */
}

/* This function is called from sqlite3_exec to print out the data */

int callback(void *NotUsed, int argc, char **argv,
char **azColName) 
{
printf("here");
	NotUsed = 0;
	for (int i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");


	return 0;
}
