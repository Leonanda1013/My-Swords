# Materi Hari Ini — 9 Agustus 2026
**Topik: Stack & Queue**

Lanjut ke struktur data yang eksplisit disebut kisi-kisi: Stack dan Queue. Keduanya STL bawaan C++, jadi kamu nggak perlu implementasi manual dari nol — fokus ke **kapan** dan **kenapa** dipakai.

---

## 1. Stack (LIFO — Last In, First Out)

Bayangin tumpukan piring: piring terakhir yang kamu taruh di atas, itu yang **pertama** kali diambil lagi.

```cpp
stack<int> st;

st.push(1);   // masukin elemen ke atas tumpukan -> [1]
st.push(2);   // -> [1, 2]
st.push(3);   // -> [1, 2, 3]

cout << st.top();  // lihat elemen paling atas (tanpa hapus) -> 3
st.pop();           // hapus elemen paling atas -> [1, 2]
cout << st.top();  // -> 2

cout << st.size();  // jumlah elemen tersisa -> 2
cout << st.empty(); // cek kosong atau enggak -> 0 (false), karena masih ada isi
```

**Kapan dipakai**: soal yang butuh "undo" terakhir, cek kecocokan tanda kurung `()[]{}`, evaluasi ekspresi matematika, atau proses yang sifatnya "yang terakhir masuk, diproses duluan".

**Contoh klasik: cek kurung seimbang**
```cpp
bool kurungSeimbang(string s){
    stack<char> st;
    for(char c : s){
        if(c == '(' || c == '[' || c == '{'){
            st.push(c);
        } else {
            if(st.empty()) return false; // ada kurung tutup tapi stack kosong
            char atas = st.top();
            st.pop();
            if(c == ')' && atas != '(') return false;
            if(c == ']' && atas != '[') return false;
            if(c == '}' && atas != '{') return false;
        }
    }
    return st.empty(); // harus kosong di akhir (semua kurung ketutup)
}
```

---

## 2. Queue (FIFO — First In, First Out)

Bayangin antrian di kasir: yang pertama datang, itu yang **pertama** dilayani.

```cpp
queue<int> q;

q.push(1);   // masuk antrian -> [1]
q.push(2);   // -> [1, 2]
q.push(3);   // -> [1, 2, 3]

cout << q.front(); // lihat elemen paling depan (tanpa hapus) -> 1
q.pop();             // hapus elemen paling depan -> [2, 3]
cout << q.front();  // -> 2

cout << q.back();   // lihat elemen paling belakang -> 3
```

**Kapan dipakai**: soal simulasi antrian, dan yang paling penting buat kamu ke depan — **BFS (Breadth-First Search)** di materi graf nanti selalu pakai queue sebagai struktur data intinya.

---

## 3. Perbedaan Kunci: Stack vs Queue

| | Stack | Queue |
|---|---|---|
| Prinsip | LIFO (terakhir masuk, duluan keluar) | FIFO (pertama masuk, duluan keluar) |
| Fungsi lihat elemen | `top()` | `front()` (dan `back()` buat elemen belakang) |
| Fungsi hapus | `pop()` (hapus dari atas) | `pop()` (hapus dari depan) |
| Contoh analogi | Tumpukan piring | Antrian kasir |
| Pemakaian umum di CP | Cek kurung, DFS (pakai stack eksplisit atau rekursi), undo | BFS, simulasi antrian |

---

## Latihan Soal — Coba di VSCode

### Soal 1: Cek Kurung Seimbang
Implementasi fungsi `kurungSeimbang` seperti contoh di atas, baca satu string dari input, cetak `"Seimbang"` atau `"Tidak Seimbang"`.

**Input**: `([{}])` → **Output**: `Seimbang`
**Input**: `([)]` → **Output**: `Tidak Seimbang`

---

### Soal 2: Simulasi Antrian Sederhana
Baca `n` perintah. Tiap perintah berupa `"masuk X"` (nomor `X` masuk antrian) atau `"keluar"` (orang paling depan keluar dari antrian, cetak nomornya). Kalau `"keluar"` dipanggil tapi antrian kosong, cetak `"Kosong"`.

**Input**:
```
5
masuk 10
masuk 20
keluar
masuk 30
keluar
```
**Expected Output**:
```
10
20
```

---

### Soal 3: Reverse Pakai Stack
Baca satu string, cetak versi terbalik dari string itu — tapi **wajib** pakai `stack`, bukan `reverse()` bawaan atau loop mundur manual.

**Input**: `halo` → **Output**: `olah`

---

### Soal 4: Cek Palindrome Pakai Stack & Queue
Baca satu string, cetak `"Ya"` atau `"Tidak"` apakah string itu palindrome — kali ini implementasi pakai **kombinasi stack dan queue** (bandingkan elemen `top()` stack dengan `front()` queue, sambil pop keduanya, sampai salah satu kosong).

**Input**: `katak` → **Output**: `Ya`

> Ini soal yang sama konsepnya kayak Soal 3 di materi kemarin (array/string), tapi sekarang dilatih pakai struktur data baru — biar kerasa bedanya sama pendekatan two-pointer.

---

### Soal 5: Simulasi Dua Stack (Tantangan)
Baca `n` perintah berupa `"push X"` (masukkan `X` ke stack), atau `"pop"` (keluarkan elemen teratas, cetak nilainya). Tapi kali ini, kalau stack sudah berisi lebih dari 5 elemen, otomatis cetak `"Penuh"` dan perintah `push` diabaikan (tidak jadi dimasukkan).

**Input**:
```
8
push 1
push 2
push 3
push 4
push 5
push 6
pop
pop
```
**Expected Output**:
```
Penuh
5
4
```

---

## Rekomendasi Soal CSES

1. **Sorting and Searching → Traffic Lights** *(opsional lompat kategori — kalau ini kerasa berat, skip dulu, ini lebih related ke topik minggu depan)*
2. Coba cari soal-soal dengan tag/kategori yang eksplisit sebut "stack" atau "queue" di Codeforces (filter by tag), CSES sendiri nggak punya kategori khusus stack/queue basic — materi ini lebih sering muncul **tersembunyi** di dalam soal graf (BFS) atau soal string/ekspresi nanti. Untuk sekarang, latihan lokal di atas sudah cukup membangun intuisi dasarnya.
3. **Introductory Problems → Gray Code** (kalau belum dikerjain minggu lalu) — bagus buat latihan mikir rekursif/backtracking sederhana yang nanti nyambung ke topik minggu depan.

Kabarin kalau ada yang mentok, terutama Soal 4 & 5 yang agak lebih menantang logikanya.