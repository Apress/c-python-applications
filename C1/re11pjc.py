#re11pjc.py
fhand = open('pjfiley.txt')

for line in fhand:
   if line[0]=='k':
      a,b = line.split('#')
      print(b)
      


fhand.close()