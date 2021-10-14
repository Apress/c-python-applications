#!/usr/bin/python

import sqlite3

conn = sqlite3.connect('Personnel.db')
cur = conn.cursor()
print ("Opened database successfully")

cur.execute('DROP TABLE IF EXISTS Personnel')
cur.execute('CREATE TABLE Personnel (id INTEGER PRIMARY KEY, name TEXT, initial TEXT, gender TEXT, age INTEGER, occup TEXT)')

cur.execute('INSERT INTO Personnel (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)', 
    (1, 'Jones', 'A', 'M', 23, 'Accountant'))
cur.execute('INSERT INTO Personnel (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)', 
    (2, 'Smith', 'J', 'M', 47, 'Salesman'))



print('Personnel:')
cur.execute('SELECT id, name, initial, gender, age, occup FROM Personnel')
for row in cur:
     print(row)

conn.commit()


conn.close()