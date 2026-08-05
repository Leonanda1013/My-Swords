# Materi Hari Ini — 4 Agustus 2026
**Topik: I/O Cepat, Long Long & Overflow, Reference Parameter, Intro Vector**

Karena kamu sudah pede sama sintaks dasar + OOP, hari ini kita skip basic banget dan langsung ke kebiasaan yang benar-benar dipakai di CP.

---

## 1. Fast I/O — Boilerplate Wajib

Setiap file CP kamu, biasakan mulai dengan ini:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // kode kamu di sini

    return 0;
}
```

**Kenapa penting:**
- `#include <bits/stdc++.h>` — satu header yang otomatis include semua library standar (vector, algorithm, map, dll). Di CP ini standar, walau "kurang rapi" untuk production code.
- `ios_base::sync_with_stdio(false); cin.tie(NULL);` — mempercepat `cin`/`cout` drastis. Tanpa ini, program kamu bisa TLE di soal dengan input/output besar (misal baca 10^6 angka), padahal logikanya sudah benar.

---

## 2. Overflow & `long long`

Ini salah satu penyebab **Wrong Answer** paling umum buat orang yang pindah dari bahasa lain ke C++.

- `int` di C++ cuma bisa nampung sampai sekitar **2.1 miliar** (2^31 - 1).
- Kalau kamu kali dua angka besar (misal `n * n` dengan n = 100.000), hasilnya bisa **overflow** dan jadi angka acak/negatif, padahal secara logika programnya sudah benar.
- Solusi: pakai `long long` (bisa nampung sampai ~9.2 x 10^18) untuk variabel yang berpotensi jadi besar — terutama hasil perkalian, penjumlahan akumulasi, atau perhitungan kombinatorik.

```cpp
int n = 100000;
long long hasil = (long long)n * n; // aman
// int hasil_salah = n * n; // ini overflow!
```

**Kebiasaan aman**: kalau ragu, langsung pakai `long long` daripada `int`. Selisih performanya kecil, tapi selisih "kena WA karena overflow vs enggak" itu besar.

---

## 3. Reference Parameter (`&`) — Bukan Pointer Mentah

Ingat pembahasan kita soal pointer — ini yang justru relevan buat CP:

```cpp
// Tanpa reference: array di-copy tiap kali fungsi dipanggil (lambat untuk array besar)
void prosesLambat(vector<int> arr) { ... }

// Dengan reference: langsung akses array asli, tidak ada copy
void prosesCepat(vector<int>& arr) { ... }
```

Aturan praktis: kalau parameter fungsi kamu adalah `vector`, `string`, atau struktur data lain yang berpotensi besar, dan kamu **tidak berniat mengubahnya**, pakai `const vector<int>& arr`. Kalau **memang mau mengubah isinya**, cukup `vector<int>& arr`.

---

## 4. Intro `vector` — Array Dinamis STL

Daripada array C-style (`int arr[100]`), di CP lebih sering pakai `vector`:

```cpp
vector<int> arr;           // vector kosong
arr.push_back(5);          // tambah elemen di belakang
arr.push_back(10);
cout << arr.size();        // jumlah elemen -> 2
cout << arr[0];            // akses seperti array biasa -> 5

vector<int> arr2(n);       // vector ukuran n, semua isinya 0
vector<int> arr3(n, -1);   // vector ukuran n, semua isinya -1
```

Kenapa `vector` lebih disukai daripada array biasa: ukurannya dinamis (nggak perlu tebak ukuran maksimal di awal), dan kompatibel langsung sama banyak fungsi STL (`sort()`, `reverse()`, dll).

---

## Latihan Soal — Bisa Dikerjain Langsung di VSCode

Kamu nggak perlu akun online judge buat latihan ini — cukup tulis kode di VSCode, compile & run, terus cocokkan manual output-nya sama expected output di bawah. Kalau nanti mau submit beneran, baru pakai Codeforces/CSES.

### Soal 1: Jumlah Besar (Overflow Check)
**Deskripsi**: Baca dua bilangan bulat `a` dan `b` (bisa sampai 10^9), lalu cetak hasil `a * b`.

**Input**: `1000000000 999999999`
**Expected Output**: `999999999000000000`

> Coba dulu pakai `int`, lihat hasilnya salah/aneh. Baru perbaiki pakai `long long`. Ini biar kamu ngerasain sendiri efek overflow-nya.

---

### Soal 2: Fast I/O Test
**Deskripsi**: Baca `n`, lalu baca `n` buah bilangan bulat. Cetak jumlah semuanya.

**Input**:
```
5
1 2 3 4 5
```
**Expected Output**: `15`

> Gunakan `vector<long long>` untuk menyimpan, dan loop pakai `for`. Pastikan boilerplate fast I/O ada di atas.

---

### Soal 3: Reference Parameter Practice
**Deskripsi**: Buat fungsi `void gandakan(vector<int>& arr)` yang mengalikan setiap elemen array dengan 2 (in-place, tanpa return value, langsung ubah array aslinya lewat reference).

**Input**: array `[1, 2, 3, 4, 5]`
**Expected Output setelah dipanggil**: `[2, 4, 6, 8, 10]`

> Cetak array sebelum dan sesudah pemanggilan fungsi untuk membuktikan reference-nya bekerja.

---

### Soal 4: Vector Basic + Sort
**Deskripsi**: Baca `n` bilangan bulat ke dalam vector, urutkan dari kecil ke besar pakai `sort()` bawaan STL, lalu cetak hasilnya.

**Input**:
```
6
5 3 8 1 9 2
```
**Expected Output**: `1 2 3 5 8 9`

```cpp
sort(arr.begin(), arr.end()); // ini fungsi sort STL, cukup 1 baris
```

---

### Soal 5: Kombinasi Semua Konsep (Tantangan)
**Deskripsi**: Baca `n` bilangan bulat (bisa besar, sampai 10^9). Cetak **hasil kali semua elemen** (pakai `long long`), dan cetak juga array yang sudah diurutkan.

**Input**:
```
4
100000 200000 3 1
```
**Expected Output**:
```
Hasil kali: 60000000000
Array terurut: 1 3 100000 200000
```

> Soal ini gabungan overflow-awareness + vector + sort — kalau kamu bisa selesaikan sendiri tanpa liat lagi ke atas, berarti materi hari ini sudah nempel.

---

## Kalau Sudah Selesai
Kerjain juga 3-5 soal di **CSES Problem Set — Introductory Problems** (gratis, nggak perlu daftar akun buat lihat soal, cuma perlu akun kalau mau submit dan cek verdict resmi). Itu bagus buat kalibrasi apakah kecepatan ngoding kamu sudah oke buat level segini.

Besok kita lanjut ke topik logika bitwise & operasi bit — kabarin kalau soal-soal di atas ada yang berasa aneh/stuck.