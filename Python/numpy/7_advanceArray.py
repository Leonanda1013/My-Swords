import numpy as np

# array dengan menggunakan tipe data tertentu
a = np.array(([1, 2, 3],[4, 5, 6]), dtype=np.float64)
print("Array dengan tipe data float64:")
print(a)

# array dengan fungsi
def pangkat2(x, y):
    return x ** 2

b = np.fromfunction(pangkat2, (3, 3), dtype=int)
print("Array dari fungsi pangkat2:")
print(b)


#array dengan iterasi

iterable = (x for x in range(6))
c = np.fromiter(iterable, dtype=int)
print("Array dari iterable:")
print(c)

iterable = (y*2 for y in range(6))
d = np.fromiter(iterable, dtype=int)
print("Array dari iterable:")
print(d)