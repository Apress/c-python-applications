#re11pjdga.py
finphand = open('pjfilezi.bin','r')
fouthand = open('pjfilezo.bin','w')

n = input('Enter an ID: ')
age = input('Enter age: ')
desc = input('Enter job description: ')

for line in finphand:
   if line[0]==n:
      a,b,c,d = line.split('-')
      print(a)
      print(b)
      print(c)
      print(d)
      print(b+' '+c+' '+d)

      c=age
      d=desc
      print(b+' '+c+' '+d)
      line=(a+'-'+b+'-'+c+'-'+d+'\n')
      fouthand.write(line)

   else: 
      fouthand.write(line)


fouthand.close()
finphand.close()


file1 = open("pjfilezo.bin", "r")
file2 = open("pjfilezi.bin", "w")
l = file1.readline()
while l:
   file2.write(l)
   l = file1.readline()
file1.close()
file2.close()


