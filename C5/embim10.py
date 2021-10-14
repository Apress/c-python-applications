#ml1pj.py
import matplotlib.pyplot as plt
import numpy as np
import math 
x = np.arange(-2, 2.1, 0.1) 

#F1 = math.pow(x,2) 
F1 = x**2
F2 = 4

plt.plot(x, F1, color="blue", linewidth=2, linestyle="-",label="y=x**2,  0 =< y <= 4" ) 

#plt.plot(x, F1, label="y=x**2") 


#x = np.linspace(-2, 2, 100)
#y = 4
#plt.plot(x, y)

# x axis values
x = [-2,-1,0,1,2]
# corresponding y axis values
y = [4,4,4,4,4]
  
# plotting the points 
plt.plot(x, y, color='blue', linestyle='-', linewidth = 2,
          markerfacecolor='red', markersize=12)


#plt.plot(x, F2, color="blue", linewidth=2, linestyle="-")
plt.grid()
plt.legend() 
plt.show()
