# Materi Hari Ini — 10 Agustus 2026
**Topik: Binary Search & Konsep Sorting Algorithms**

Kamu udah pakai `sort()` bawaan STL beberapa kali. Hari ini kita bedah **kenapa** sorting penting buat efisiensi, terus fokus utama ke **Binary Search** — salah satu teknik paling sering dipakai di CP.

---

## 1. Kenapa Sorting Penting (Bukan Cuma Buat Rapi-Rapi Data)

Constraint soal itu penentu algoritma apa yang bisa dipakai. Ingat pembahasan time limit kemarin: **1 detik ≈ 10^8 operasi**. Kalau kamu cek satu-satu (linear search) di data yang **belum diurutkan** dan ukurannya besar (misal n = 10^6, dicek berkali-kali), itu bisa gampang TLE.

Tapi kalau data **sudah diurutkan**, kamu bisa pakai **Binary Search** yang jauh lebih cepat — inilah kenapa sorting sering jadi langkah pertama sebelum searching di banyak soal.

---

## 2. Kompleksitas: Kenapa Binary Search Jauh Lebih Cepat

| Teknik | Kompleksitas | Untuk n = 1.000.000 |
|---|---|---|
| Linear Search | O(n) | ~1.000.000 langkah |
| Binary Search | O(log n) | ~20 langkah |

Binary Search kerja dengan cara **membagi dua** ruang pencarian tiap langkah (makanya butuh data terurut) — bukan cek satu-satu dari awal.

## 3. Implementasi Binary Search Manual

```cpp
bool cariAngka(vector<int>& arr, int target){
    int kiri = 0, kanan = arr.size() - 1;
    while(kiri <= kanan){
        int tengah = kiri + (kanan - kiri) / 2;  // hindari overflow drpd (kiri+kanan)/2
        if(arr[tengah] == target){
            return true;
        } else if(arr[tengah] < target){
            kiri = tengah + 1;   // target ada di sisi kanan
        } else {
            kanan = tengah - 1;  // target ada di sisi kiri
        }
    }
    return false; // nggak ketemu
}
```

**Penting**: array **harus** sudah terurut sebelum binary search dipakai — kalau belum, `sort()` dulu.

## 4. Fungsi STL: `lower_bound` & `upper_bound`

C++ punya fungsi bawaan yang lebih praktis dari implementasi manual:

```cpp
vector<int> arr = {1, 3, 3, 5, 7, 9};

// lower_bound: cari posisi PERTAMA elemen >= target
auto it1 = lower_bound(arr.begin(), arr.end(), 3);
cout << (it1 - arr.begin()); // -> 1 (index pertama yang nilainya >= 3)

// upper_bound: cari posisi PERTAMA elemen > target
auto it2 = upper_bound(arr.begin(), arr.end(), 3);
cout << (it2 - arr.begin()); // -> 3 (index pertama yang nilainya > 3)

// Cek apakah target ada di array
bool ada = binary_search(arr.begin(), arr.end(), 5); // -> true
```

`lower_bound` dan `upper_bound` ini kelihatan sepele, tapi **sangat** sering dipakai buat soal-soal yang butuh hitung "berapa banyak elemen ≤ X" atau "posisi elemen terdekat" — jauh lebih cepat nulisnya daripada implementasi binary search manual tiap kali.

---

## 5. Sorting Algorithms — Konsep (Nggak Perlu Hafal Implementasi Semuanya)

Kisi-kisi nyebut beberapa algoritma sorting spesifik. Kamu **nggak perlu** hafal implementasi manual semuanya luar kepala (di CP praktiknya hampir selalu pakai `sort()` bawaan STL yang udah dioptimasi), tapi perlu paham **konsep & kompleksitasnya** karena bisa muncul di soal teori:

| Algoritma | Kompleksitas Rata-rata | Konsep Singkat |
|---|---|---|
| Bubble Sort | O(n²) | Bandingin elemen bersebelahan berulang kali, tukar kalau salah urutan |
| Insertion Sort | O(n²) | Ambil elemen satu-satu, sisipkan ke posisi yang benar di bagian yang sudah terurut |
| Quicksort | O(n log n) rata-rata | Pilih pivot, elemen lebih kecil ke kiri, lebih besar ke kanan, rekursif |
| Merge Sort | O(n log n) | Bagi dua terus rekursif, lalu gabung (merge) hasil yang sudah terurut |
| Heapsort | O(n log n) | Manfaatkan struktur binary heap buat ambil elemen terkecil/terbesar berulang |

**Yang perlu kamu inget praktisnya**: `sort()` bawaan C++ itu udah pakai kombinasi algoritma O(n log n) di belakang layar (biasanya introsort — campuran quicksort, heapsort, insertion sort). Jadi di 99% soal CP, **tinggal panggil `sort()`**, nggak perlu nulis manual. Yang penting kamu paham **kenapa O(n log n) jauh lebih baik dari O(n²)** untuk data besar.

---

## Latihan Soal — Coba di VSCode

### Soal 1: Binary Search Manual
Implementasi fungsi `cariAngka` seperti contoh di atas. Baca array (sudah terurut) dan sebuah target, cetak `"Ketemu"` atau `"Tidak Ketemu"`.

**Input**:
```
5
1 3 5 7 9
5
```
**Expected Output**: `Ketemu`

---

### Soal 2: Hitung Berapa Kali Muncul (pakai lower_bound & upper_bound)
Baca array (belum tentu terurut), lalu baca target. Urutkan array dulu, lalu hitung **berapa kali** target muncul di array — wajib pakai `lower_bound` dan `upper_bound` (bukan loop manual hitung satu-satu).

**Input**:
```
7
3 1 3 3 5 3 9
3
```
**Expected Output**: `4`

> Hint: hasil `upper_bound - lower_bound` (posisinya, bukan nilainya) itu langsung jumlah kemunculan.

---

### Soal 3: Cari Posisi Elemen Terdekat
Baca array terurut dan sebuah target yang **mungkin tidak ada** di array. Cetak nilai elemen di array yang **paling dekat** dengan target (kalau seri, pilih yang lebih kecil).

**Input**:
```
5
1 4 6 8 10
7
```
**Expected Output**: `6`
(karena `7` lebih dekat ke `6` selisih 1, dibanding ke `8` selisih 1 juga — seri, jadi pilih yang lebih kecil yaitu `6`)

> Hint: pakai `lower_bound` buat cari posisi elemen pertama yang `>= target`, terus bandingkan elemen di posisi itu dengan elemen sebelumnya.

---

### Soal 4: Simulasi Bubble Sort Manual
Implementasi bubble sort dari nol (pakai nested loop, tanpa `sort()`), lalu cetak array hasilnya. Ini biar kamu ngerasain langsung kenapa ini lebih lambat dari `sort()` bawaan.

**Input**:
```
5
5 2 8 1 9
```
**Expected Output**: `1 2 5 8 9`

---

### Soal 5: Bandingkan Waktu Eksekusi (Eksperimen)
Generate array acak berisi 50.000 elemen (bisa pakai `rand()` dalam loop), lalu:
1. Sort pakai bubble sort manual dari Soal 4, catat berapa lama waktunya (pakai `chrono` atau ngerasa manual dari jeda program)
2. Sort array yang sama pakai `sort()` bawaan STL, catat waktunya

**Tujuan soal ini**: ngerasain sendiri gap performa O(n²) vs O(n log n) di data yang cukup besar — bubble sort mungkin kerasa jelas lebih lambat atau bahkan nge-freeze sebentar, sedangkan `sort()` bawaan hampir instan.

```cpp
#include <chrono>
// ...
auto mulai = chrono::high_resolution_clock::now();
// proses sorting di sini
auto selesai = chrono::high_resolution_clock::now();
auto durasi = chrono::duration_cast<chrono::milliseconds>(selesai - mulai);
cout << "Waktu: " << durasi.count() << " ms" << endl;
```

---

## Rekomendasi Soal CSES (Kategori Sorting and Searching)

1. **Distinct Numbers** — pemanasan ringan, langsung pakai konsep sort + hitung unik
2. **Apartments** — soal klasik binary search / two-pointer setelah sorting, bagus banget buat ngasah intuisi hari ini
3. **Ferris Wheel** — mirip konsepnya, latihan greedy + sorting
4. **Sum of Two Values** — kombinasi sorting + two-pointer/binary search buat cari pasangan angka

Kabarin progress-nya, terutama Soal 5 (eksperimen waktu) — itu paling penting buat ngerasain sendiri kenapa kompleksitas algoritma itu bukan cuma teori doang.