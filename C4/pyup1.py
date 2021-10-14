import sqlite3


conn = sqlite3.connect('Personnel.db') # open connection to database file Personnel.db

cur = conn.cursor()#open connection to ‘cursor’ which facilitates SQL
# Now update the row in the table  
# we want to set the age for the person named Smith to be 24  

try:
                cur.execute("UPDATE Personnel SET age = 24 WHERE name = 'Smith'")
 except Error as e:
                print(e)
# Select everything contained in the table  

cur.execute("SELECT * FROM Personnel")

cur.execute('SELECT id, name, initial, gender, age, occup FROM Personnel')
for row in cur:
     print(row)
    
    

conn.commit()#commit these transaction so they can be seen by other programs
cur.close()	
