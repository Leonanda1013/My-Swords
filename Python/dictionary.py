data_list = ["apel", "jeruk", "mangga"]
print("data list :", data_list[1])


data_dict = {
    "nama": "ucup",
    "umur": 17,
}

print("data ", "nama",  " :", data_dict["nama"])

LENGTH = len(data_dict)
print("panjang data dictionary :", LENGTH)

KEYS = data_dict.keys()
print("key pada dictionary :", KEYS)
VALUE = data_dict.values()
print("value pada dictionary :", VALUE)
KEY = "nama"
CHECK_KEY = KEY in data_dict
print(f"apakah ada key {KEY} pada dictionary :", CHECK_KEY)


#looping
for KEYS in data_dict.keys():
    print("key :", KEYS)
for VALUES in data_dict.values():
    print("value :", VALUES)
for KEY, VALUE in data_dict.items():
    print("key :", KEY, "value :", VALUE)


#CRUD
data_dict["alamat"] = "indonesia" #create
data_dict.update({"nama": "otong"}) #update
print(data_dict)