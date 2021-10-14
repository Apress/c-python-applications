import sqlite3


conn = sqlite3.connect('Personnel.db') # open connection to database file Personnel.db
cur = conn.cursor()#open connection to ‘cursor’ which facilitates SQL
# we want to set the age for the person whose name is entered into ‘namein’ to be the age which is entered into ‘agein’  


while True:
    namein = input('Enter an name, or quit: ')
    if(namein == 'quit'): break
    print(namein)
    agein = input('Enter age: ')
    
    
    # Using a while loop
    tot0 = 0
# Now update the row in the table  

    try:

        cur.execute("UPDATE Personnel SET age = ? WHERE name = ?", (agein,namein,))
    
    except:
        print('Error in Update')

    
    #conn.total_changes returns total changes since connection
    # by setting tot0 to 0 before this update then only this
    # update is checked
    tot = conn.total_changes
    print(tot)
    if tot == tot0:
        print('Table not updated')
    else:
        # Select everything contained in the table  

        cur.execute('SELECT id, name, initial, gender, age, occup FROM Personnel')
        for row in cur:
             print(row)

    

conn.commit()#commit these transaction so they can be seen by other programs


cur.close()#close the database connection
	

