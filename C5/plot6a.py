import numpy as np 
from matplotlib import pyplot as plt 

x = np.arange(0,10) 
y = x + 3 
plt.title("Embedded ") 
plt.xlabel("x axis") 
plt.ylabel("y axis") 
plt.plot(x,y) 
plt.show()