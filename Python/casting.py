#casting
data_integer = 9
data_float = float(data_integer)
data_string = str(data_integer)
print("data : ", data_string)
print("bertipe : ", type(data_string))


#input
data = input("masukkan data : ")
print("data : ", data, ", bertipe : ", type(data))
#input integer
data_int = int(input("masukkan data integer : "))
print("data : ", data_int, ", bertipe : ", type(data_int))
#input float
data_float = float(input("masukkan data float : "))
print("data : ", data_float, ", bertipe : ", type(data_float))
#input boolean
data_bool = bool(int(input("masukkan data boolean (0/1) : ")))
print("data : ", data_bool, ", bertipe : ", type(data_bool))