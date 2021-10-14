

fileout = open("pjfileqi.bin", "w")


line1 = "a-Jones-D-37-accountant-45000\n"
fileout.write(line1)

line2 = "b-Smith-A-42-HR-55000 \n"
fileout.write(line2)

line3 = "c-Allen-R-28-Secretary-40000 \n"
fileout.write(line3)

line4 = "d-Bradley-S-26-Programmer-50000 \n"
fileout.write(line4)

fileout.close()



filein = open("pjfileqi.bin", "r")

a=filein.readline()
b=filein.readline()
c=filein.readline()
d=filein.readline()

print(a)
print(b)
print(c)
print(d)


filein.close()