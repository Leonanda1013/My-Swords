# 🚀 CHEATSHEET KEBUT COMPETITIVE PROGRAMMING (CODE TODAY 2026)
> Khusus persiapan Babak Penyisihan (2 Jam / 120 Menit) — Target Siap: 18 September 2026

---

## 0. BOILERPLATE WAJIB
```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define fi first
#define se second

const int MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    // Solusi per test case di sini
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t; // Buka jika ada multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}
```

---

## 1. MATEMATIKA & TEORI BILANGAN

### A. Aritmatika Modulo
```cpp
long long add(long long a, long long b, long long m = MOD) { return (a % m + b % m) % m; }
long long sub(long long a, long long b, long long m = MOD) { return ((a % m - b % m) % m + m) % m; }
long long mul(long long a, long long b, long long m = MOD) { return ((a % m) * (b % m)) % m; }
```

### B. Fast Exponentiation (Binary Exponentiation) $O(\log B)$
```cpp
long long binpow(long long a, long long b, long long m = MOD) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

// Modular Inverse (Fermat's Little Theorem, jika MOD bilangan prima)
long long modInverse(long long n, long long m = MOD) {
    return binpow(n, m - 2, m);
}

// Pembagian Modulo: (a / b) % MOD = a * modInverse(b) % MOD
long long divMod(long long a, long long b, long long m = MOD) {
    return mul(a, modInverse(b, m), m);
}
```

### C. Sieve of Eratosthenes (Prima sampai $N \approx 10^7$)
```cpp
const int MAX = 1e6 + 5;
vector<bool> is_prime(MAX, true);
vector<int> primes;

void sieve(int n) {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
}
```

### D. FPB / GCD & KPK / LCM
```cpp
// C++17 ke atas sudah punya bawaan di <numeric>
long long fpb = std::gcd(a, b);
long long kpk = std::lcm(a, b);

// Manual jika diperlukan:
long long gcd_manual(long long a, long long b) {
    return b == 0 ? a : gcd_manual(b, a % b);
}
```

---

## 2. SEARCHING & GREEDY

### A. Binary Search on Answer (Tebak Jawaban)
Gunakan saat diminta mencari nilai **minimum yang mungkin** atau **maksimum yang mungkin** dengan fungsi monoton.
```cpp
bool cek(long long mid) {
    // Return true jika nilai 'mid' valid/memenuhi syarat
    return true; 
}

long long low = 1, high = 1e18, ans = -1;
while (low <= high) {
    long long mid = low + (high - low) / 2;
    if (cek(mid)) {
        ans = mid;        // Simpan kandidat terbaik
        high = mid - 1;   // Jika mencari MINIMUM, coba cari yang lebih kecil
        // Atau low = mid + 1 jika mencari MAKSIMUM
    } else {
        low = mid + 1;    // Jika mencari MINIMUM
        // Atau high = mid - 1 jika mencari MAKSIMUM
    }
}
```

### B. Two Pointers (Cari Pasangan Jumlah $X$)
```cpp
sort(arr.begin(), arr.end());
int l = 0, r = n - 1;
while (l < r) {
    int sum = arr[l] + arr[r];
    if (sum == target) {
        // Ketemu!
        break;
    } else if (sum < target) {
        l++;
    } else {
        r--;
    }
}
```

---

## 3. GRAF & TREE

### A. Representasi Graf (Adjacency List)
```cpp
int n, m;
vector<vector<int>> adj;

void read_graph() {
    cin >> n >> m;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Jika graf tidak berarah
    }
}
```

### B. BFS Grid (Jarak Terpendek Labirin / Peta)
```cpp
int R, C;
vector<string> grid;
int dist[1005][1005];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void bfs_grid(int startX, int startY) {
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    
    q.push({startX, startY});
    dist[startX][startY] = 0;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}
```

### C. Dijkstra (Shortest Path Bobot Positif) $O((V + E) \log V)$
```cpp
vector<vector<pair<int, long long>>> adj; // {tetangga, bobot}
vector<long long> dist;

void dijkstra(int start, int n) {
    dist.assign(n + 1, 1e18);
    // Min-heap: {jarak, node}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            long long w = edge.second;
            
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}
```

---

## 4. STRUKTUR DATA SAKTI (DSU & FENWICK TREE)

### A. Disjoint Set Union (DSU / Union-Find) — Hanya ~15 Baris!
```cpp
struct DSU {
    vector<int> parent, sz;
    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        sz.assign(n + 1, 1);
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // Path compression
    }
    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            sz[root_i] += sz[root_j];
            return true; // Berhasil digabung
        }
        return false; // Sudah dalam komponen yang sama
    }
};
```

### B. Kruskal MST (Minimum Spanning Tree)
```cpp
struct Edge {
    int u, v;
    long long w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

long long kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long mst_cost = 0;
    int edges_count = 0;
    
    for (auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_cost += e.w;
            edges_count++;
        }
    }
    if (edges_count != n - 1) return -1; // Graf tidak terhubung
    return mst_cost;
}
```

### C. Fenwick Tree (Binary Indexed Tree / BIT) — Point Update & Range Query
Jauh lebih singkat & cepat ditulis dibanding Segment Tree di kontes 2 jam!
```cpp
struct FenwickTree {
    int n;
    vector<long long> bit;
    FenwickTree(int n) : n(n), bit(n + 1, 0) {}

    void update(int idx, long long delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }

    long long query(int idx) {
        long long sum = 0;
        for (; idx > 0; idx -= idx & -idx)
            sum += bit[idx];
        return sum;
    }

    long long range_query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
```

---

## 5. DYNAMIC PROGRAMMING (DP) KLASIK

### A. 0/1 Knapsack (Space-Optimized 1D)
Tiap barang hanya boleh diambil maksimal 1 kali.
```cpp
// W: kapasitas ransel, n: jumlah barang
// wt: array berat, val: array nilai
vector<long long> dp(W + 1, 0);

for (int i = 0; i < n; i++) {
    // Loop mundur dari W ke wt[i] agar barang tidak terpakai dua kali!
    for (int w = W; w >= wt[i]; w--) {
        dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
    }
}
cout << dp[W] << "\n";
```

### B. Coin Change (Unbounded Knapsack / Minimum Koin)
Tiap nominal koin boleh dipakai berkali-kali.
```cpp
// Target jumlah: X, koin: c_1, c_2, ..., c_k
vector<int> dp(X + 1, 1e9);
dp[0] = 0;

for (int w = 1; w <= X; w++) {
    for (int coin : coins) {
        if (w - coin >= 0) {
            dp[w] = min(dp[w], dp[w - coin] + 1);
        }
    }
}
int ans = (dp[X] >= 1e9 ? -1 : dp[X]);
```

### C. Longest Common Subsequence (LCS)
```cpp
int lcs(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
```

---

## 6. GEOMETRI DASAR & TRIK

### A. Cross Product (Orientasi 3 Titik 2D)
```cpp
struct Point {
    long long x, y;
};

// Menghitung cross product (B - A) x (C - A)
// > 0 : Belok Kiri (Counter-Clockwise)
// < 0 : Belok Kanan (Clockwise)
// = 0 : Kolinier (Segaris lurus)
long long cross_product(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}
```
