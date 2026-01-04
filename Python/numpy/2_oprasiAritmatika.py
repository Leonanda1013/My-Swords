import numpy as np

a = [1, 2, 3]
b = [4, 5, 6]
z = np.array([1, 2, 3])

#  perasi penjumlahan
c = np.array(a) + np.array(b)
print(c)

# operasi pengurangan
d = np.array(a) - np.array(b)
print(d)

# operasi perkalian (elemen wise)
e = np.array(a) * np.array(b) 
print(e)

# operasi pembagian
f = np.array(a) / np.array(b)
print(f)

# operasi pangkat
g = np.array(a) ** 2
print(g)

# opraasi menjadikan 3d//tidak bisaaa

h = z*c
