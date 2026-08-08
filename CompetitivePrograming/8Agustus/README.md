# Materi Hari Ini — 8 Agustus 2026
**Topik: Array Multidimensi & Operasi String**

Lanjut dari bitwise kemarin, sekarang masuk ke poin kisi-kisi berikutnya: array (termasuk multidimensi) dan string beserta operasinya.

---

## 1. Array Multidimensi (2D Array / Grid)

Di CP, array 2D sering dipakai buat representasi grid/papan (misal: peta, papan catur, matriks). Ada dua cara umum bikin di C++:

**Cara 1: Vector of vector**
```cpp
int baris = 3, kolom = 4;
vector<vector<int>> grid(baris, vector<int>(kolom, 0));
// grid[i][j] sekarang bisa diakses, semua nilai awal 0

grid[1][2] = 5;   // baris ke-1, kolom ke-2 diisi 5
cout << grid[1][2]; // cetak 5
```

**Cara 2: Baca grid langsung dari input** (paling sering muncul di soal — biasanya dikasih dalam bentuk baris-baris karakter)
```cpp
int n, m;
cin >> n >> m;
vector<vector<char>> grid(n, vector<char>(m));
for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        cin >> grid[i][j];
    }
}
```

**Cara akses tetangga (atas/bawah/kiri/kanan)** — ini pola yang bakal sering kepake pas masuk materi graf (BFS/DFS) minggu-minggu depan:
```cpp
int dx[] = {-1, 1, 0, 0}; // atas, bawah, kiri, kanan (delta baris)
int dy[] = {0, 0, -1, 1}; // delta kolom

for(int d = 0; d < 4; d++){
    int ni = i + dx[d];
    int nj = j + dy[d];
    // cek ni, nj masih dalam batas grid sebelum diakses
    if(ni >= 0 && ni < n && nj >= 0 && nj < m){
        // proses grid[ni][nj]
    }
}
```

---

## 2. Operasi String di C++

String di C++ punya banyak fungsi bawaan yang berguna:

```cpp
string s = "Vincetius";

s.length();          // atau s.size() -> panjang string (9)
s[0];                 // akses karakter per-index -> 'V'
s.substr(0, 4);       // ambil 4 karakter mulai index 0 -> "Vinc"
s.substr(4);          // ambil dari index 4 sampai akhir -> "etius"

s.find("cet");        // cari posisi substring -> 3 (index awal ketemu)
s.find("xyz");        // kalau nggak ketemu -> string::npos (nilai khusus)

reverse(s.begin(), s.end()); // balik string in-place (butuh <algorithm>, sudah include lewat bits/stdc++)

s += "!";             // concatenation, gabung string -> "Vincetius!"

// Konversi
string angka = to_string(123);   // int -> string: "123"
int n = stoi("456");             // string -> int: 456
```

**Loop per karakter** (dua cara umum):
```cpp
for(int i = 0; i < s.length(); i++){
    cout << s[i];
}

// atau pakai range-based for (lebih ringkas)
for(char c : s){
    cout << c;
}
```

**Cek palindrome** (pola soal yang sering muncul):
```cpp
bool isPalindrome(string s){
    int kiri = 0, kanan = s.length() - 1;
    while(kiri < kanan){
        if(s[kiri] != s[kanan]) return false;
        kiri++;
        kanan--;
    }
    return true;
}
```

---

## Latihan Soal — Coba di VSCode

### Soal 1: Buat & Isi Grid 2D
Baca `n` dan `m` (ukuran grid), lalu baca `n*m` bilangan bulat untuk mengisi grid baris per baris. Cetak grid itu kembali dalam format baris x kolom.

**Input**:
```
2 3
1 2 3 4 5 6
```
**Expected Output**:
```
1 2 3
4 5 6
```

---

### Soal 2: Jumlah per Baris & Kolom
Dari grid yang sama seperti Soal 1, cetak jumlah tiap baris, lalu jumlah tiap kolom.

**Input**:
```
2 3
1 2 3 4 5 6
```
**Expected Output**:
```
Jumlah baris: 6 15
Jumlah kolom: 5 7 9
```

---

### Soal 3: Cek Palindrome
Baca satu string, cetak `"Ya"` kalau string itu palindrome, `"Tidak"` kalau bukan. Implementasi fungsi `isPalindrome` sendiri (jangan cuma `reverse()` lalu compare — coba pakai teknik two-pointer kayak contoh di atas).

**Input**: `katak` → **Output**: `Ya`
**Input**: `hello` → **Output**: `Tidak`

---

### Soal 4: Hitung Karakter Unik
Baca satu string, cetak berapa banyak karakter **berbeda** yang muncul di dalamnya (case-sensitive, anggap huruf besar & kecil beda).

**Input**: `programming` → **Output**: `8`
(karena huruf unik: p, r, o, g, a, m, i, n)

> Hint: manfaatkan `set<char>` — coba explore sendiri cara pakainya, ini struktur data STL lain yang bakal sering kepake ke depan.

---

### Soal 5: Cek Tetangga di Grid (Pemanasan buat Graf)
Baca grid ukuran `n x m` isinya karakter `'#'` (dinding) atau `'.'` (jalan). Baca posisi `(baris, kolom)` tertentu, cetak berapa banyak dari 4 tetangga (atas/bawah/kiri/kanan) posisi itu yang merupakan `'.'` dan masih dalam batas grid.

**Input**:
```
3 3
...
.#.
...
1 1
```
(posisi baris=1, kolom=1 — itu sel `'#'` di tengah, tapi kita tetap cek tetangganya)

**Expected Output**: `4`
(karena atas, bawah, kiri, kanan dari posisi tengah semuanya `'.'`)

> Ini pemanasan penting buat BFS/DFS yang bakal kita bahas pas masuk materi graf.

---

## Rekomendasi Soal CSES (Kategori Introductory Problems)

1. **Repetitions** *(kalau kemarin belum sempat)* — langsung latihan loop per karakter string
2. **Creating Strings** — manipulasi & generate string, bagus buat mengasah intuisi string di C++
3. **Palindrome Reorder** — nyambung langsung ke konsep palindrome dari Soal 3 di atas
4. **Number Spiral** — latihan mikir pola pakai grid/koordinat 2D (index matematis, bukan simulasi penuh — good buat latihan mikir efisien)

Kalau nemu yang stuck, kirim kodenya kayak biasa ya.