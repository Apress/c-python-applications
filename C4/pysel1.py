import sqlite3


conn = sqlite3.connect('Personnel.db') # open connection to database file Personnel.db
cur = conn.cursor()#open connection to ‘cursor’ which facilitates SQL

# Select one row contained in the table where the age is 59
# If we did not have LIMIT 1 then every row which had an age of 59 would be displayed 

cur.execute("SELECT * FROM Personnel  WHERE age = 59 LIMIT 1")
for row in cur:
     print(row)


conn.commit()#commit these transaction so they can be seen by other programs

cur.close()#close the database connection		
