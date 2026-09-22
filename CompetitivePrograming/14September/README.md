# Materi Kebut Hari 1 — 14 September 2026
**Topik: Teori Bilangan & Aritmatika Modulo (Fast Pow, Modulo Inverse, Sieve Prima, GCD)**

Selamat datang di sesi kebut pertama! Topik hari ini adalah **senjata paling sering keluar** di soal-soal kontes pemrograman: manipulasi bilangan besar, modulo, dan bilangan prima.

---

## 1. Aturan Emas Modulo Arithmetic (`MOD = 10^9 + 7`)

Hampir setiap soal CP yang jawabannya bisa sangat besar akan meminta: *"Cetak jawaban dalam modulo 1.000.000.007"*.

Ada 3 aturan wajib:
```cpp
const int MOD = 1e9 + 7;

// 1. Penjumlahan
long long tambah = (a % MOD + b % MOD) % MOD;

// 2. Pengurangan (Waspada hasil negatif di C++!)
// (-3 % 7) di C++ hasilnya -3, padahal modulo matematika harus positif!
long long kurang = ((a % MOD - b % MOD) % MOD + MOD) % MOD;

// 3. Perkalian (Wajib casting ke long long sebelum dikali agar tidak overflow!)
long long kali = ((a % MOD) * (b % MOD)) % MOD;
```

> **Ingat:** Jangan pernah membagi langsung dengan operator `/` di bawah modulo! Pembagian butuh *Modular Inverse* (dibahas di poin 3).

---

## 2. Fast Exponentiation / Binary Exponentiation ($O(\log B)$)

Jika kamu diminta menghitung $A^B \pmod{MOD}$ di mana $B = 10^9$:
- Loop `for` biasa berjalan $10^9$ kali $\rightarrow$ **Pasti TLE** (butuh ~10 detik).
- Fast Exponentiation membagi pangkatnya menjadi dua tiap langkah $\rightarrow$ Cuma butuh $\approx 30$ operasi!

### Cara Kerja:
- Jika $B$ genap: $A^B = (A^{B/2})^2$
- Jika $B$ ganjil: $A^B = A \times A^{B-1}$

```cpp
long long binpow(long long a, long long b, long long m = 1e9 + 7) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m; // Jika bit terakhir 1 (ganjil)
        a = (a * a) % m;                // Kuadratkan basis
        b >>= 1;                        // Bagi 2 pangkatnya
    }
    return res;
}
```

---

## 3. Pembagian Modulo & Teorema Fermat

Di aritmatika modulo:
$$\frac{A}{B} \pmod M \neq \frac{A \pmod M}{B \pmod M}$$

Sebagai gantinya, kita kalikan dengan **Modular Inverse** dari $B$:
$$\frac{A}{B} \equiv A \times B^{-1} \pmod M$$

Menurut **Fermat's Little Theorem**, jika $M$ bilangan prima:
$$B^{-1} \equiv B^{M-2} \pmod M$$

Artinya, mencari invers dari $B$ cukup dengan menghitung **`binpow(B, MOD - 2)`**!
```cpp
long long modInverse(long long b, long long m = 1e9 + 7) {
    return binpow(b, m - 2, m);
}

long long bagi(long long a, long long b, long long m = 1e9 + 7) {
    return ( (a % m) * modInverse(b, m) ) % m;
}
```

---

## 4. Sieve of Eratosthenes (Tapis Prima)

Jika soal menanyakan keprimaan banyak angka sampai $N \le 10^6$:
- Jangan cek satu-satu dengan loop $O(\sqrt{N})$ berkali-kali.
- Gunakan **Sieve**: tandai semua kelipatan bilangan prima sebagai komposit sejak awal.

```cpp
const int MAX = 1e6 + 5;
vector<bool> is_prime(MAX, true);
vector<int> primes;

void sieve(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
}
```

---

## 5. FPB (GCD) & KPK (LCM)

Di C++17, kamu tidak perlu mengetik fungsi Euclidean manual lagi. Cukup include `<numeric>`:
```cpp
#include <numeric>

long long fpb = std::gcd(a, b);
long long kpk = std::lcm(a, b);
```
Rumus relasi penting:
$$\text{LCM}(a, b) = \frac{a \times b}{\text{GCD}(a, b)}$$

---

## 🎯 Latihan Hari Ini (Kerjakan di folder `14September/`)

### Soal 1: Perpangkatan Modulo Raksasa
Diberikan dua bilangan $A$ dan $B$ ($1 \le A, B \le 10^{18}$). Hitung nilai $A^B \pmod{10^9 + 7}$.
- **Input**: `2 10`
- **Output**: `1024`
- **Input**: `3 1000000000`
- **Output**: `918907876`

---

### Soal 2: Pengurangan Aman & Modulo Negatif
Diberikan $A$ dan $B$ ($1 \le A, B \le 10^{18}$). Hitung:
1. $(A + B) \pmod{10^9 + 7}$
2. $(A - B) \pmod{10^9 + 7}$ (Pastikan tidak pernah bernilai negatif!)
3. $(A \times B) \pmod{10^9 + 7}$

- **Input**: `5 8`
- **Output**:
  ```
  Tambah: 13
  Kurang: 1000000004
  Kali: 40
  ```

---

### Soal 3: Hitung Banyak Prima $\le N$
Diberikan bilangan bulat $N$ ($1 \le N \le 10^6$). Cetak berapa banyak bilangan prima yang kurang dari atau sama dengan $N$.
- **Input**: `10`
- **Output**: `4` (prima: 2, 3, 5, 7)
- **Input**: `100`
- **Output**: `25`

---

### Soal 4: Pembagian Modulo (Kombinasi Sederhana)
Ada $N$ orang yang saling berjabat tangan satu sama lain tepat sekali. Jumlah total jabat tangan adalah $\frac{N(N - 1)}{2}$.
Diberikan $N$ ($2 \le N \le 10^9$), hitung total jabat tangan $\pmod{10^9 + 7}$.
*(Gunakan modular inverse atau bagi dulu dengan 2 sebelum modulo!)*
- **Input**: `4`
- **Output**: `6`
- **Input**: `1000000000`
- **Output**: `499999996`
