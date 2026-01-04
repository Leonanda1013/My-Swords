import numpy as np

a = np.array(([1, 2, 3],[4, 5, 6],))

# transphose
print("Original Array:")
print("ini adalah ukuran matrixnya ",a.shape)
print(a)

# transpose
print("Transpose Array:")
print(a.T)
print(np.transpose(a))

#flatten
print("Flatten Array:")
b = a.flatten()
print(b)
print(np.ravel(a))

# reshape
print("Reshape Array:")
c = a.reshape(3,2)
print(c)
d = a.reshape(6,1)
print(d)

# resize
print("Resize Array:")
a.resize(3,2)
print(a)