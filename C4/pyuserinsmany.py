#!/usr/bin/python

import sqlite3

conn = sqlite3.connect('Personnel.db') # open connection to database file Personnel.db
cur = conn.cursor()#open connection to ‘cursor’ which facilitates SQL
print ("Opened database successfully")
# User is asked to enter the name, ID, initial, gender, age and occupation

while True:
    namein = input('Enter an name, or quit: ') # age stored in namein
    
    if(namein == 'quit'): break  #exit the while loop
    idin = input('Enter ID: ') # id stored in ‘idin’
    initial = input('Enter initial: ') # initial stored in ‘initial’
    gender = input('Enter gender: ') # gender stored in ‘gender’
    agein = input('Enter age: ') # age stored in ‘agein’
    occup = input('Enter occupation: ') # occupation stored in ‘occup’

# Now Insert row into the table using the values entered

    cur.execute('INSERT INTO Personnel (id, name, initial, gender, age, occup) VALUES (?, ?, ?, ?, ?, ?)',(idin, namein, initial, gender, agein, occup))
    #break

print('Personnel:')
# Select everything contained in the table 

cur.execute('SELECT id, name, initial, gender, age, occup FROM Personnel')
for row in cur:
     print(row) # print each row contained in the table


conn.commit()#commit these transaction so they can be seen by other programs

conn.close()#close the database connection
