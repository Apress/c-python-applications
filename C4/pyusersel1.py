import sqlite3


conn = sqlite3.connect('Personnel.db') # open connection to database file Personnel.db
cur = conn.cursor()#open connection to ‘cursor’ which facilitates SQL


while True:
    namein = input('Enter an name, or quit: ')
    if(namein == 'quit'): break
    print(namein)
    
    cur.execute('SELECT age FROM Personnel WHERE name = ? LIMIT 1', (namein, ))


    (age, ) = cur.fetchone()
    print(age)
    break
conn.commit()#commit these transaction so they can be seen by other programs

cur.close()#close the database connection
