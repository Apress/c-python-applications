#!/usr/bin/python

import sqlite3

conn = sqlite3.connect('staff.db')
cur = conn.cursor()
print ("Opened database successfully")

cur.execute('DROP TABLE IF EXISTS staff')
cur.execute('CREATE TABLE staff (id INTEGER, name TEXT, initial, gender TEXT, age INTEGER, occup TEXT)')

cur.execute('INSERT INTO staff (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)', 
    (1, 'Jones', 'A', 'M', 23, 'Accountant'))
cur.execute('INSERT INTO staff (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)', 
    (2, 'Smith', 'J', 'M', 47, 'Salesman'))
cur.execute('INSERT INTO staff (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)',
    (3, 'Zeiss', 'H', 'F', 38, 'Architect'))
cur.execute('INSERT INTO staff (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)',
    (4, 'Blaine', 'S', 'F', 28, 'SE'))
cur.execute('INSERT INTO staff (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)',
    (5, 'Postlethwaite', 'D', 'M', 63, 'Advisor'))
cur.execute('INSERT INTO staff (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)',
    (6, 'Junkers', 'A', 'M', 59, 'Designer'))

print('staff:')
cur.execute('SELECT id, name, initial, gender, age, occup FROM staff')
for row in cur:
     print(row)

conn.commit()



cur.execute('DROP TABLE IF EXISTS supply')
cur.execute('CREATE TABLE supply (id INTEGER, coname TEXT, address TEXT, type TEXT)')

cur.execute('INSERT INTO supply (id, coname, address, type) VALUES (?, ?, ?, ?)', 
    (1, 'Lenox Co.', '95th Street', 'Concrete'))
cur.execute('INSERT INTO supply (id, coname, address, type) VALUES (?, ?, ?, ?)', 
    (2, 'City Builders', 'Avon Ave', 'Bricks'))
cur.execute('INSERT INTO supply (id, coname, address, type) VALUES (?, ?, ?, ?)',
    (3, 'Portway', 'New Strand', 'Windows'))
cur.execute('INSERT INTO supply (id, coname, address, type) VALUES (?, ?, ?, ?)',
    (4, 'Huygens Inc', 'Corona Drive', 'Wood panelling'))


print('supply:')
cur.execute('SELECT id, coname, address, type FROM supply')
for row in cur:
     print(row)

conn.commit()







conn.close()