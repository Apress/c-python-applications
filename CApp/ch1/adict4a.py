
#in python

#>>> my_dict = {'a' : 'one', 'b' : 'two'}

#>>> 'a' in my_dict
#TRUE
#>>> 'c' in my_dict
#FALSE

#in adict4a.py program
my_dict = {'a' : 'one', 'b' : 'two'}
print("Enter key to be tested: ")
testkey = input()
found = 0
for item in my_dict:
    if testkey in my_dict:
        print ("specified found")
        found = 1
        break
if found == 0: 
   print ("specified not found")
