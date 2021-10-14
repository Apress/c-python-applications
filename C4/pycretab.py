import sqlite3

conn = sqlite3.connect('Personnel.db') # open connection to database file Personnel.db
cur = conn.cursor() #open connection to ‘cursor’ which facilitates SQL
print ("Opened database successfully")

cur.execute('DROP TABLE IF EXISTS Personnel') # delete the table if it already exists
cur.execute('CREATE TABLE Personnel (id INTEGER PRIMARY KEY, name TEXT, initial TEXT, gender TEXT, age INTEGER, occup TEXT)') #create the table, specifying the items in each row

conn.close() # close the database connection
