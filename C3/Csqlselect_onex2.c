#include <sqlite3.h>
#include <stdio.h>
int callback(void *, int, char **, char **);
int main(void) {
sqlite3 *db;
char *err_msg = 0;
int rc = sqlite3_open("test.db", &db);
if (rc != SQLITE_OK) {
fprintf(stderr, "Cannot open database: %s\n",
sqlite3_errmsg(db));
sqlite3_close(db);
return 1;
}
int idin,idnew;


printf("enter current ID \n");
	scanf("%d", &idin);
/*printf("enter new Name \n");
	scanf("%s", &namenew);*/
/*cidnew[1] = idnew + '0';*/
char str1[] = "SELECT name, age, occupation FROM Personnel WHERE id = ";
char str2[] = " WHERE ID = ";
char str3[10]; 
char str4[10]; 
char str5[] = ";";

/*printf("cidnew = %s\n",cidnew);*/
/*puts(cidnew);*/





printf("idin = %d\n", idin);
sprintf(str4, "%d", idin);
/*printf("namenew = %s\n", namenew);
sprintf(str3, "%s", namenew);*/

/*printf(str3);*/
/*strcat(str1,str3);
printf(str1);

strcat(str1,str2);
printf(str1);*/

strcat(str1,str4);
/*printf(str1);*/
strcat(str1,str5);
printf(str1);
printf("\n");

/*char *sql = "UPDATE cars SET Name = 'namenew' WHERE Name = 7";*/
/*char *sql = "UPDATE cars SET id = 17 WHERE id = 7";*/
char *sql = str1;








/*char *sql = "SELECT name, age, occupation FROM Personnel WHERE id = 5";*/
rc = sqlite3_exec(db, sql, callback, 0, &err_msg);
if (rc != SQLITE_OK ) {
fprintf(stderr, "Failed to select data\n");
fprintf(stderr, "SQL error: %s\n", err_msg);
sqlite3_free(err_msg);
sqlite3_close(db);
return 1;
}
sqlite3_close(db);
return 0;
}
int callback(void *NotUsed, int argc, char **argv,
char **azColName) {
NotUsed = 0;
for (int i = 0; i < argc; i++) {
printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
}
printf("\n");


return 0;
}