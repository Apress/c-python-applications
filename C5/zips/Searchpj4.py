import matplotlib.pyplot as plt
import numpy as np
fhand = open('cofm5a.bin','r') #file of (x,y) values created by Cofm5a.c

count = 0
#if there are 8 entered coordinates then this will be the arrays
#xvals = [0,1,2,3,4,5,6,7]
#yvals = [0,1,2,3,4,5,6,7]
#xvals = [0]*8
#yvals = [0]*8

y = np.loadtxt("cofm5a.bin") # read x,y values
print("Data read from cofm5a.bin")
print(y)

z = np.loadtxt("cofm5acnt.bin") # read count of points, xcofm and ycofm
print("Data read from cofm5acnt.bin")
print(z)
a,p,j = z # split the 3 z values into separate variables
zint = int(a)
print("zint is " ,zint) # total number of points
string_p = str(p)
print("string_p is ",string_p ) # x value of c of m
string_j = str(j)
print("string_j is ",string_j ) # y value of c of m

xvals = [0]*zint
yvals = [0]*zint
# store the x and y coordinates into xvals[] and yvals[]
for x in range(zint-1):
    a,b = y[x]
    xvals[x] = a
    yvals[x] = b

plt.xlabel('x values') 
plt.ylabel('y values')
plt.title(' CofM Graph (red spot is Centre of Mass)')
plt.plot(xvals, yvals, "ob")
plt.plot(p, j, "or")
plt.show()
