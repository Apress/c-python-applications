#readfile7a.py
import matplotlib.pyplot as plt
import numpy as np

fhand = open('capm2.bin','r')
fhand2 = open('capm.bin','r')
fhand3 = open('capm2cnt.bin','r')


z = np.loadtxt("capm2cnt.bin")
print("Data read from capm2cnt.bin")
print("z follows")
print(z)
a = z
zint = int(a)
print("zint follows")
print(zint)


count = 0

content = fhand2.readlines()

y = np.loadtxt("capm.bin")
print("Data read from capm.bin")
print(y)

# y now contains the x and y values of the 4 points
#[[1. 2.]
# [2. 5.]
# [3. 6.]
# [4. 9.]]

#zeroise the two arrays
xvals = [0]*zint
yvals = [0]*zint

print("xvalsfirst")
print(xvals)
print("yvalsfirst")
print(yvals)


#separate the x and y values
for x in range(zint):
    a,b = y[x]
    xvals[x] = a
    yvals[x] = b

print("xvals")
print(xvals)
print("yvals")
print(yvals)

plt.plot(xvals, yvals, "ob")



count = 0
for line in fhand:
    line = line.rstrip()
print(line)
    

x = np.linspace(-5,5,10)
print('x follows')
print(x)

print('line follows')
print(line)

a = 'y='
b = a + line
print(b)
y= eval(line)
print('y follows')
print(y)

plt.plot(x, y, '-r', label=b)

plt.title(b)
plt.xlabel('x', color='#1C2833')
plt.ylabel('y', color='#1C2833')
plt.legend(loc='upper left')
plt.grid()
plt.show()
