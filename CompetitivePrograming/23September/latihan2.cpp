#include <iostream>
using namespace std;

int main(){
    int angka;
    cout << "Masukkan angka :" << endl;
    cin >> angka;

    for (int i = 1; i <= angka; i++){
        if (i % 3 == 0) {
            continue;
        }
        cout << i << " ";
    }
    cout << endl;

    int n = 1;
    int total = 0;
    while (n <= angka)
    {
        total = total + n;  // SEMUA angka ditambahkan, tanpa skip
        n++;                 // increment ini sekarang tidak akan pernah ke-skip
    }
    cout << total << endl;

    return 0;
}