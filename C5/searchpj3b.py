import matplotlib.pyplot as plt
import numpy as np


#if there are 8 entered coordinates the this will be the arrays
#xvals = [0,1,2,3,4,5,6,7]
#yvals = [0,1,2,3,4,5,6,7]
#xvals = [0]*8
#yvals = [0]*8

# Read data from pmccf.bin file

y = np.loadtxt("pmccf2.bin")
print("Data read from pmccf2.bin")
print("y = ",y)

# Read data from pmccfcnt.bin file

z = np.loadtxt("pmccfcnt2.bin")
print("Data read from pmccfcnt2.bin")
print("z = ",z)
a,b = z # a is no. of coords entered, b is PMCC value

#zint is the number of coordinates entered
zint = int(a)
print("number of coordinates entered = ", zint)

print("PMCC = ", b)
float_b = b;
string_b = str(float_b)

# Set up the arrays for the graph

xvals = [0]*zint #length of array is num. of coords entered 
yvals = [0]*zint #length of array is num. of coords entered

# set up the x and y arrays from the values entered
for x in range(zint):
    a,b = y[x]
    xvals[x] = a
    yvals[x] = b

# Print the x and y values to the user 

print("xvals = ",xvals)
print("yvals = ",yvals)

# Display the graph

plt.xlabel('x values') 
plt.ylabel('y values')
plt.title('PMCC Test Graph')
plt.text(1.0, 10, 'PMCC =')
plt.text(2.0, 10, string_b)

plt.plot(xvals, yvals, "ob")
plt.show() 