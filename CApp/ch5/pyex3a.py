import matplotlib.pyplot as plt
import numpy as np


# Read data from pmccf.bin file

x = np.loadtxt("histn.bin")
print("Data read from histn.bin")
print("x = ",x)


# Set up the arrays for the graph

xvals = [0]*20 #length of array is num. of coords entered 

zint = 20
# set up the x array from the values entered
for b in range(zint):
    a = x[b]
    xvals[b] = a
    

# Print the x and y values to the user 

print("xvals = ",xvals)

number_of_bins = 10

n = plt.hist(xvals, number_of_bins, facecolor='blue')

print("Counts in each bin")
print(n[0]) # counts in each bin




# Display the graph

plt.xlabel('marks (%)')
plt.ylabel('Number of Students')
plt.title('Histogram Exam Marks')
plt.show()
