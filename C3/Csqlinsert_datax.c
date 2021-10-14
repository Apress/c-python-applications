#include <sqlite3.h>
#include <stdio.h>
int main(void)
{
	sqlite3 *db;
	char *err_msg = 0;
	int rc = sqlite3_open("test.db", &db);
	if (rc != SQLITE_OK)
     {
		fprintf(stderr, "Cannot open database: %s\n", 			sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
	}
	char *sql = "DROP TABLE IF EXISTS Personnel;"
	"CREATE TABLE Personnel(Id INT PRIMARY KEY, Name TEXT, 	Age INT, Occupation);"
	"INSERT INTO Personnel VALUES(1, 'Brown', 42, 	'accountant');"
	"INSERT INTO Personnel VALUES(2, 'Jones', 27, 	'programmer');"
	"INSERT INTO Personnel VALUES(3, 'White', 30, 	'engineer');"
	"INSERT INTO Personnel VALUES(4, 'Green', 29, 	'electrician');"
	"INSERT INTO Personnel VALUES(5, 'Smith', 35, 	'manager');"
	"INSERT INTO Personnel VALUES(6, 'Black', 21, 	'secretary');"
	"INSERT INTO Personnel VALUES(7, 'Allen', 41, 	'cleaner');"
	"INSERT INTO Personnel VALUES(8, 'Stone', 21, 	'receptionist');";
	rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
	if (rc != SQLITE_OK )
	{
		fprintf(stderr, "SQL error: %s\n", err_msg);
		sqlite3_free(err_msg);
		sqlite3_close(db);
		return 1;
	}
	sqlite3_close(db);
	return 0;
}
