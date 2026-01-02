from . import database

def create_firstdatabase(DB_NAME):
    id = input("Masukkan ID: ")
    penulis = input("Masukkan Penulis: ")
    judul = input("Masukkan Judul: ")
    tahun = input("Masukkan Tahun: ")

    data = database.TAMPLATE.copy()
    data["id"] = id
    data["pengarang"] = penulis
    data["judul"] = judul
    data["tahun"] = tahun
    with open(DB_NAME, "w") as file:
        file.write(f"{data['id']},{data['pengarang']},{data['judul']},{data['tahun']}\n")


