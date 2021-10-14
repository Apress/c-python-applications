import matplotlib.pyplot as plt
import numpy as np 
X = np.linspace(0, 2 * np.pi, 50, endpoint=True) 

F1 = 2 * np.sin(X) 
F2 = np.sin(X) 
F3 = np.cos(X) 

plt.plot(X, F1, color="blue", linewidth=2, linestyle="-") 
plt.plot(X, F2, color="red", linewidth=2, linestyle="-") 
plt.plot(X, F3, color="green", linewidth=2, linestyle="-") 

plt.plot(X, F1, label="2sin(x)") 
plt.plot(X, F2, label="sin(x)") 
plt.plot(X, F3, label="cos(x)") 

plt.legend() 
plt.show() 