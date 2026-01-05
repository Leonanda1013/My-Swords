import numpy as np

a = np.array([1, 2, 3])
b = np.array([4, 5, 6])

# stacking arrays vertically
c = np.vstack((a, b))
print("Vertical Stack:")
print(c)

# stacking arrays horizontally
d = np.hstack((a, b))
print("Horizontal Stack:")
print(d)

# matriks 2d
e = np.array([[1, 2, 3], [4, 5, 6]])
f = np.array([[7, 8, 9], [10, 11, 12]])

# stacking 2D arrays vertically
g = np.vstack((e, f))
print("Vertical Stack 2D:")
print(g)

# stacking 2D arrays horizontally
h = np.hstack((e, f))
print("Horizontal Stack 2D:")
print(h)