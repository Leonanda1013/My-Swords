import numpy as np

a = np.arange(10)**2
print(a)

# mengambil elemen a
print("elemen a ke-2 :", a[1])
print("elemen 1 dari belakang", a[-1])

#slicing
print("menganbil range element 1 sampai 7:", a[0:7])
print("menganbil range element awal sampai 7:", a[:7])
print("menganbil range element akhir sampai 7:", a[7:])

# iterasi
for i in a:
    print("elemen:", i)
    if i == a[5]:
        break