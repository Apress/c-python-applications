#!/usr/bin/python

import sqlite3

conn = sqlite3.connect('Personnel.db')
cur = conn.cursor()
print ("Opened database successfully")


while True:
    acct = input('Enter an name, or quit: ')
    
    if(acct == 'quit'): break 
    idin = input('Enter ID: ')
    initial = input('Enter initial: ')
    gender = input('Enter gender: ')
    agein = input('Enter age: ')
    occup = input('Enter occupation: ')

    cur.execute('INSERT INTO Personnel (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)',(idin, acct, initial, gender, agein, occup))
    #break THIS IS THE ONLY CHANGE TO THE PROGRAM. WHEN YOU ARE
    # ASKED to 'Enter an name, or quit: ' at the start of the while
    # loop then entering 'quit' exits from the loop, so you can enter
    # as many rows as you want.

print('Personnel:')
cur.execute('SELECT id, name, initial, gender, age, occup FROM Personnel')
for row in cur:
     print(row)

conn.commit()

conn.close()