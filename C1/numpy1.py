import numpy as np

a = np.array([1, 2, 3])   # Create a rank 1 array
print(type(a))            # Prints "<class 'numpy.ndarray'>"
print(a.shape)            # Prints "(3,)"
print(a[0], a[1], a[2])   # Prints "1 2 3"
a[0] = 5                  # Change an element of the array
print(a)                  # Prints "[5, 2, 3]"

b = np.array([[1,2,3],[4,5,6]])    # Create a rank 2 array

#1 2 3
#4 5 6
# reference elements counting from 0
# so b[1, 2] is row 1 (2nd row) column 2 (3rd column)
#so if you print b[1, 2] you get 6
print("b[1, 2] follows")
print(b[1, 2])

print(b.shape)                     # Prints "(2, 3)" 2 rows 3 columns
print(b[0, 0], b[0, 1], b[0, 2])   # Prints "1 2 3"
print(b[1, 0], b[1, 1], b[1, 2])   # Prints "4 5 6"
print(b[0, 0], b[0, 1], b[1, 0])   # Prints "1 2 4"


