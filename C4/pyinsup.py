import sqlite3

conn = sqlite3.connect('Personnel.db') # open connection to database file Personnel.db

cur = conn.cursor()#open connection to ‘cursor’ which facilitates SQL
#insert the row, specifying the items in the row
cur.execute('INSERT INTO Personnel (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)', 
    (25,'Van der Kirchoff', 'I', 'M', 34, 'plumber'))
#update a different row, specifying the changed item in the row

cur.execute("UPDATE Personnel SET age = 28 WHERE name = 'Smith'")
# Select everything contained in the table 

cur.execute("SELECT * FROM Personnel ")
cur.execute('SELECT id, name, initial, gender, age, occup FROM Personnel')
for row in cur:
     print(row)    

    
conn.commit()#commit these transaction so they can be seen by other programs

cur.close()#close the database connection
	
