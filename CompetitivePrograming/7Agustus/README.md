# Materi Hari Ini — 7 Agustus 2026
**Topik: Operator Bitwise & Logika Dasar (AND/OR/XOR, Modus Ponens & Tollens)**

Progress kamu sejauh ini udah bagus — I/O, overflow, reference, vector, sort semua udah clear lewat implementasi sendiri. Hari ini kita masuk ke topik yang eksplisit disebut di kisi-kisi: **operator bitwise** dan **logika dasar**.

---

## 1. Operator Bitwise

Ini beda dari operator logika biasa (`&&`, `||`) — bitwise beroperasi **langsung di level bit** (representasi biner) dari angka.

| Operator | Nama | Contoh | Hasil |
|---|---|---|---|
| `&` | AND | `5 & 3` | `1` (0101 & 0011 = 0001) |
| `\|` | OR | `5 \| 3` | `7` (0101 \| 0011 = 0111) |
| `^` | XOR | `5 ^ 3` | `6` (0101 ^ 0011 = 0110) |
| `~` | NOT | `~5` | membalik semua bit |
| `<<` | Shift kiri | `5 << 1` | `10` (geser bit ke kiri = kali 2) |
| `>>` | Shift kanan | `5 >> 1` | `2` (geser bit ke kanan = bagi 2, dibulatkan ke bawah) |

**Kenapa ini berguna di CP** (bukan cuma teori):

```cpp
// Cek genap/ganjil tanpa modulo
if (n & 1) { /* ganjil */ } else { /* genap */ }

// Kali/bagi 2 pakai shift (lebih cepat dari * dan /)
int dikali2 = n << 1;
int dibagi2 = n >> 1;

// Cek apakah bit ke-k bernilai 1
bool bitAktif = (n >> k) & 1;

// Set bit ke-k jadi 1
n = n | (1 << k);

// Clear (matikan) bit ke-k jadi 0
n = n & ~(1 << k);

// Cek apakah n adalah pangkat 2 (trik klasik CP)
bool isPowerOfTwo = (n > 0) && ((n & (n - 1)) == 0);
```

Trik terakhir itu sering banget muncul di soal — worth diinget: kalau `n` pangkat 2 (contoh `8 = 1000`), maka `n-1` (`7 = 0111`) itu kebalikan pola bit-nya persis, jadi `n & (n-1)` selalu `0`.

---

## 2. Operator Logika (Boolean) vs Bitwise

Jangan ketuker sama operator logika biasa yang kamu pakai di `if`:

```cpp
bool a = true, b = false;
a && b  // logika AND -> false (operasi di level boolean, bukan per-bit)
a || b  // logika OR  -> true
```

Beda `&` vs `&&`: `&` beroperasi ke **tiap bit** dari angka (bisa dipakai ke `int`), sedangkan `&&` beroperasi di level **boolean** (`true`/`false`) — biasa dipakai buat gabung kondisi di `if`. Ini salah satu typo paling umum di CP (nulis `&` padahal maksudnya `&&`, atau sebaliknya), jadi perhatiin konteksnya.

---

## 3. Tabel Kebenaran (Truth Table)

Kisi-kisi nyebut ini eksplisit — intinya cuma nge-list semua kemungkinan hasil dari kombinasi input boolean:

| A | B | A AND B | A OR B | A XOR B |
|---|---|---------|--------|---------|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 | 0 |

Pola gampang diinget: **XOR = "beda hasilnya 1, sama hasilnya 0"**. Ini sering dipakai buat trik-trik soal (misal: cari satu-satunya angka yang muncul ganjil kali di array, semua elemen di-XOR semua, yang muncul genap kali bakal saling "menghapus").

## 4. Modus Ponens & Modus Tollens

Ini konsep logika proposisional dasar, bukan soal pemrograman langsung, tapi bisa muncul di soal logika/pseudocode:

- **Modus Ponens**: kalau `P → Q` (jika P maka Q) benar, dan `P` benar, maka **Q pasti benar**.
  > Contoh: "Kalau hujan, jalanan basah" (benar). "Sekarang hujan" (benar). Kesimpulan: "Jalanan basah."

- **Modus Tollens**: kalau `P → Q` benar, dan `Q` **salah** (tidak terjadi), maka **P pasti salah**.
  > Contoh: "Kalau hujan, jalanan basah" (benar). "Jalanan ternyata tidak basah." Kesimpulan: "Berarti tidak hujan."

Yang penting dipahami: dua pola penarikan kesimpulan valid ini sering muncul di soal logika berbentuk cerita/pseudocode — biasanya kamu diminta nentuin kesimpulan mana yang valid dari premis yang dikasih.

---

## Latihan Soal — Coba di VSCode

### Soal 1: Cek Genap/Ganjil Pakai Bitwise
Baca satu bilangan `n`, cetak `"Genap"` atau `"Ganjil"` — tapi wajib pakai operator `&`, bukan `%`.

**Input**: `7` → **Output**: `Ganjil`
**Input**: `10` → **Output**: `Genap`

---

### Soal 2: Hitung Jumlah Bit 1 (Popcount Manual)
Baca satu bilangan `n`, hitung berapa banyak bit bernilai 1 dalam representasi binernya, **tanpa** pakai fungsi bawaan `__builtin_popcount()` — coba implementasi manual pakai loop + shift.

**Input**: `13` (biner: `1101`) → **Output**: `3`

> Hint: loop selama `n > 0`, tiap iterasi cek bit terakhir pakai `n & 1`, lalu geser `n = n >> 1`.

---

### Soal 3: Cek Pangkat Dua
Baca satu bilangan `n`, cetak `"Ya"` kalau `n` adalah pangkat dari 2 (1, 2, 4, 8, 16, ...), atau `"Tidak"` kalau bukan. Pakai trik `n & (n-1)`.

**Input**: `16` → **Output**: `Ya`
**Input**: `18` → **Output**: `Tidak`

---

### Soal 4: Set & Clear Bit
Baca `n` dan `k`. Cetak nilai `n` setelah bit ke-`k` di-**set** jadi 1, lalu cetak lagi nilai `n` (dari hasil sebelumnya) setelah bit ke-`k` itu di-**clear** jadi 0 (harusnya balik ke nilai asli kalau bit ke-k awalnya 0).

**Input**: `n=5, k=1` (biner `n`: `101`)
**Output**:
```
Setelah set bit ke-1: 7
Setelah clear bit ke-1: 5
```

---

### Soal 5: Truth Table Generator
Baca dua nilai boolean `a` dan `b` (dalam bentuk `0`/`1`), cetak hasil AND, OR, XOR-nya dalam satu baris.

**Input**: `1 0`
**Output**: `AND=0 OR=1 XOR=1`

---

## Rekomendasi Soal CSES (Kategori Introductory Problems)

Kerjain urutan ini setelah latihan lokal di atas:

1. **Bit Strings** — langsung berhubungan sama representasi biner, pemanasan pas buat topik hari ini
2. **Trailing Zeros** — sedikit mikir soal pola bit di angka faktorial
3. **Coin Piles** — bukan bitwise langsung, tapi ngelatih logika kondisi yang mirip pola pikir modus ponens/tollens (kalau kondisi A gak terpenuhi, langsung tau hasilnya)
4. **Gray Code** *(opsional, agak lebih menantang)* — kalau soal 1-3 kerasa lancar, ini bagus buat latihan mikir pola bit yang lebih kompleks

Kalau ada yang WA atau TLE pas submit, bawa kodenya ke sini kayak biasa — kita bedah bareng.