import numpy as np

# random matrix 3x3 dengan nilai antara 1 sampai 10
a = np.random.randint(1, 11, size=(1,10))
print("Random integer between 1 and 10:", a)

# mengurutkan elemen pada array
sorted_a = np.sort(a)
print("Sorted array:", sorted_a)

# mengurutkan elemen pada array secara descending
sorted_desc_a = np.sort(a)[::-1]
print("Sorted array (descending):", sorted_desc_a)

# maximum dan minimum
max_value = np.max(a)
min_value = np.min(a)
print("Maximum value:", max_value)
print("Minimum value:", min_value)

# pakai nama
dytipe = [('name', 'S10'), ('age', 'i4')]
values = [('Alice', 25), ('Bob', 20), ('Charlie', 30)]
b = np.array(values, dtype=dytipe)
sorted_b = np.sort(b, order='age')
print("Sorted by age:")
print(sorted_b)