#re11pjd.py
fhand = open('Peoplex.txt')


n = input('Enter an ID: ')

for line in fhand:
   
   if line[0]==n:
      a,b,c,d = line.split('-')
      print(b+' '+c+' '+d)
      


fhand.close()