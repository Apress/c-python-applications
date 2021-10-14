import matplotlib.pyplot as plt
import numpy as np

fhand = open('capm2.bin','r') #file containing the calculated regression equation
# 'capm.bin' is the file containing the coordinate points
# 'capm2cnt.bin'is the # file containing the number of coordinate points



z = np.loadtxt("capm2cnt.bin") # read the number of points and store in z
print("Data read from capm2cnt.bin")
print("z follows")
print(z)
a = z # this is the number of coordinate points
zint = int(a) # convert the number to an int
print("zint follows")
print(zint)


count = 0



y = np.loadtxt("capm.bin") # read the 4 points and store in y
print("Data read from capm.bin")
print(y)

# y now contains the x and y values of the 4 points
#[[1. 2.]
# [2. 5.]
# [3. 6.]
# [4. 9.]]

#zeroise the two arrays using zint as the count of points
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
print(line) # the calculated regression equation
    
x = np.linspace(-5,5,10)
print('x follows')
print(x)

print('line follows')
print(line)
#line is 0.000000+2.200000*x

a = 'y='
b = a + line # b is y = 0.000000+2.200000*x

print(b)
y= eval(line) # use the regression equation to calculate the y-values from the x-values
print('y follows')
print(y)

plt.plot(x, y, '-r', label=b)

plt.title(b)
plt.xlabel('x', color='#1C2833')
plt.ylabel('y', color='#1C2833')
plt.legend(loc='upper left')
plt.grid()
plt.show()
