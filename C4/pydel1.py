import sqlite3

conn = sqlite3.connect('Personnel.db') # open connection to database file Personnel.db
cur = conn.cursor()#open connection to ‘cursor’ which facilitates SQL
print ("Opened database successfully")


namein = input('Enter an name, or quit: ')
    
cur.execute('DELETE FROM Personnel WHERE name = ?',(namein,))

print('Personnel:')
cur.execute('SELECT id, name, initial, gender, age, occup FROM Personnel')
for row in cur:
     print(row)

conn.commit()#commit these transaction so they can be seen by other programs

conn.close()#close the database connection
