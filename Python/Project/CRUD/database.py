from .import operasi

DB_NAME = "database.txt"
TAMPLATE = {
    "id": "",
    "pengarang": "",
    "judul": "",
    "tahun": ""
}

def init_console():
    try:
        with open(DB_NAME, "r") as file:
            print("Database ditemukan.")
    except:
        print("Database tidak ditemukan. Membuat database baru...")
        operasi.create_firstdatabase(DB_NAME)
        print("Database berhasil dibuat.")