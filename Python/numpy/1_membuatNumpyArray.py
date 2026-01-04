import numpy as np

#membuat vektor
a = np.array([1,2,3,4])
print(a)

#membuat vector dengan range
#arange(start, stop, step)
b = np.arange(1,10,2)
print(b)

#membuat linspace
c = np.linspace(0,10,5)
print(c)

#membuat matrix 2D
d = np.array([[1,2,3],[4,5,6]])
print(d)

#membuat matriks nilai 0
e = np.zeros((3,4))
print(e)

#membuat matriks nilai 1
f = np.ones((2,3))
print(f)

#membuat matriks identitas
g = np.eye(4)
g = np.identity(4)
print(g)