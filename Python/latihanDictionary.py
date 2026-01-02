mahasiswa = {
    "nama" : "Budi",
    "nim" : "2141760001",
    "jurusan" : "Teknik Informatika"
} 

print("nama mahasiswa :", mahasiswa["nama"])
print("jurusan mahasiswa :", mahasiswa["jurusan"])

mahasiswa.update({"ipk" : 3.75})
print("data mahasiswa setelah ditambah :", mahasiswa)

mahasiswa.update({"jurusan" : "Sistem Informasi"})
print("data mahasiswa setelah ditambah :", mahasiswa)

mahasiswa.pop("nim")
print("data mahasiswa setelah ditambah :", mahasiswa)



nilai = {
    "Andi": 85,
    "Budi": 90,
    "Citra": 78
}

for nama, nilai_ujian in nilai.items():
    print(nama, "mendapat nilai", nilai_ujian)


KEY = "Doni"
CHECK_KEY = KEY in nilai
print(f"apakah ada nama {KEY} dalam nilai :", CHECK_KEY)
if CHECK_KEY == False:
    print(f"menambahkan data nilai untuk {KEY}")
    nilai[KEY] = 88

LEN = len(nilai)
print("panjang data nilai :", len(nilai))

data_mahasiswa = {
    "2141760001": {"nama": "Andi", "ipk": 3.6},
    "2141760002": {"nama": "Budi", "ipk": 3.8}
}

print("data mahasiswa dengan NIM 2141760001 :", data_mahasiswa["2141760001"]["nama"])

nilai = {
    "Matematika": 80,
    "Fisika": 85,
    "Kimia": 90
}
nilaiTotal = 0
for mata_kuliah, nilai_ujian in nilai.items():
    nilaiTotal += nilai_ujian;
print("nilai total :", nilaiTotal)
nilaiRataRata = nilaiTotal / len(nilai)
print("nilai rata-rata :", nilaiRataRata)