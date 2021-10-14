import sqlite3


conn = sqlite3.connect('Personnel.db') # open connection to database file Personnel.db
cur = conn.cursor()#open connection to ‘cursor’ which facilitates SQL


cur.execute("SELECT * FROM Personnel ORDER BY age DESC")
for row in cur:
     print(row)
    

    
conn.commit()#commit these transaction so they can be seen by other programs


cur.close()#close the database connection
