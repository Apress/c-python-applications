#include <sqlite3.h>
#include <stdio.h>
int callback(void *, int, char **, char **);
int main(void)
{
	sqlite3 *db;
	char *err_msg = 0;
	int rc = sqlite3_open("test.db", &db);/* check the database */

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n",
		sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
	}
	char *sql = "SELECT * FROM Personnel GROUP BY age HAVING age > 25";
	rc = sqlite3_exec(db, sql, callback, 0, &err_msg);/*execute the command */

	if (rc != SQLITE_OK )
	{
		fprintf(stderr, "Failed to select data\n");
		fprintf(stderr, "SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
		sqlite3_close(db);
		return 1;
	}
	sqlite3_close(db); /* close the database connection */

	return 0;
}

/* This function is called from sqlite3_exec to print out the data */
int callback(void *NotUsed, int argc, char **argv,
char **azColName)
{
	NotUsed = 0;
	for (int i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? 			argv[i] : "NULL");
	}
	printf("\n");


	return 0;
}

