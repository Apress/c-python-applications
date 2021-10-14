import sqlite3

conn = sqlite3.connect('Personnel.db') # open connection to database file Personnel.db
cur = conn.cursor()#open connection to ‘cursor’ which facilitates SQL

print ("Opened database successfully")

# Now Insert six rows into the table  


cur.execute('INSERT INTO Personnel (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)', 
    (11, 'Jones', 'A', 'M', 23, 'Accountant'))
cur.execute('INSERT INTO Personnel (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)', 
    (12, 'Smith', 'J', 'M', 47, 'Salesman'))
cur.execute('INSERT INTO Personnel (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)',
    (13, 'Zeiss', 'H', 'F', 38, 'Architect'))
cur.execute('INSERT INTO Personnel (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)',
    (14, 'Blaine', 'S', 'F', 28, 'SE'))
cur.execute('INSERT INTO Personnel (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)',
    (15, 'Postlethwaite', 'D', 'M', 63, 'Advisor'))
cur.execute('INSERT INTO Personnel (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)',
    (16, 'Junkers', 'A', 'M', 59, 'Designer'))

print('Personnel:')
cur.execute('SELECT id, name, initial, gender, age, occup FROM Personnel') # Select everything contained in the table  

for row in cur:
     print(row) # print each row contained in the table


conn.commit()#commit these transaction so they can be seen by other programs
conn.close() #close the database connection
