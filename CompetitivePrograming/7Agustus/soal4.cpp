#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int k;
    cin >> n ;
    cin >> k;

    n =  n | (1<<k);
    cout << "Setelah set bit ke-" << k << ": " << n << endl;

    n = n & ~(1<<k);
    cout << "Setelah clear bit ke-" << k << ": " << n << endl;
}