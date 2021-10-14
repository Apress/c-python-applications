#include <sqlite3.h>
#include <stdio.h>
int main(void)
{
	int idin,agenew,optin;
	char namenew[13];
	char occupnew[15];
	
	sqlite3 *db;
	char *err_msg = 0;
	sqlite3_stmt *res;
	int rc = sqlite3_open("test.db", &db); /* check the database */

	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database: %s\n", 			sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
	}
	char str3[20]; 
	char str1[80] = "UPDATE Personnel SET ";
	
	char str9[2];
 	char str15[] = ";";
	char str16[] = ", ";
	char str17[] = ")";
	char str18[] = "\'";

	printf("enter id \n");
	scanf("%d", &idin);

/* The user can amend either age, name or occupation for the specified id for the row. We ask them which they want to amend */

	printf("Do you want to update age,name or occupation (1,2 	or 3)\n");
	scanf("%d", &optin);
	if(optin == 1)
	{
		/* Amend the age */

		printf("enter new age \n");
		scanf("%d", &agenew);

		strcat(str1," age = "); /* add age */
		strcat(str1,str18);
		sprintf(str3, "%d", agenew); /* copy new age to str3*/
		strcat(str1,str3); /* add new age */
		strcat(str1,str18); /* add quote */
	}
	else if(optin == 2)
	{
		/* Amend the name */

		printf("enter new name \n");
		scanf("%s", namenew);
		strcat(str1," name = ");
		strcat(str1,str18);
		strcpy(str3, namenew); /* copy new name to str3*/

		strcat(str1,str3); /* add new name */
		strcat(str1,str18); /* add quote */

	}
	else
	{
		/* Amend the occupation */

		printf("enter new occupation \n");
		scanf("%s", occupnew);
		strcat(str1," Occupation = ");
		strcpy(str3,occupnew); /* copy new occupation to str3*/
		
		strcat(str1,str18); /* add quote */
		strcat(str1,str3); /* add new occupation */
		strcat(str1,str18); /* add quote */
	}



	char str2[] = " WHERE id = ";

	char str4[6]; 

	strcat(str1,str2); /* copy ‘WHERE id = ‘ string */
	sprintf(str4, "%d", idin); /* copy id into str4 */
	printf(str4);
	strcat(str1,str4); /* copy id into final string */


	printf(str1);

/* so, if we want to update the occupation for ID=12 */
/* our completed string will be :- */
/* UPDATE Personnel SET  Occupation = 'Programmer' WHERE id = 12 */


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
