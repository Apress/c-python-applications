import sqlite3


conn = sqlite3.connect('Personnel.db') # open connection to database file Personnel.db
cur = conn.cursor()#open connection to ‘cursor’ which facilitates SQL



ageins = input('Enter age: ')

print(ageins)

while True:
    
    # Using a while loop
       

    cur.execute("SELECT * FROM Personnel GROUP BY age HAVING age > ?",(ageins,))
    for row in cur:
         print(row)

    break
    

conn.commit()#commit these transaction so they can be seen by other programs


cur.close()#close the database connection

