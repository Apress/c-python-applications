import matplotlib.pyplot as plt
import numpy as np

fhand = open('output.txt','r')
lines = [' ',' ']
count = 0
#store the two lines in lines[0] and lines[1]
for line in fhand:
    lines[count] = line
    count = count + 1
print('lines[0] The first line read from output.txt')
print(lines[0])
print('lines[1] The second line read from output.txt')
print(lines[1])
#strip the newline character from each of the lines
l1 = lines[0].rstrip('\n')
l2 = lines[1].rstrip('\n')
print('l1 The first line read from output.txt with newline character removed ')
print(l1)
print('l2 The second line read from output.txt with newline character removed ')
print(l2)


def graph(formula, x_range):  
# function to plot the graph
    x = np.array(x_range)  
    y = eval(formula) # evaluate the formula to give the y-values
    plt.xlabel('x values') 
    plt.ylabel('y values')
    plt.title('Line Graph ')


    plt.plot(x, y)  
    plt.show()

#get the second line and store the two points on aint and bint
aint=int(l2[3])
#b = 0
bint=int(l2[0])
# call the graph-plotting function with the equation and range as parameters
graph(l1, range(bint, aint))


