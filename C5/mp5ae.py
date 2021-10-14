import numpy as np
import matplotlib.pyplot as plt

# Choose evenly spaced x intervals
x = np.arange(-2*np.pi, 2*np.pi, 0.1)

# plot y = tan(x)
plt.plot(x, np.tan(x))

# Set the range of the axes
plt.axis([-2*np.pi, 2*np.pi, -2, 2])

# Include a title
plt.title('y = tan(x)')

# Optional grid-lines
plt.grid()

plt.xlabel('x values') 
plt.ylabel('y values')


# Show the graph
plt.show()