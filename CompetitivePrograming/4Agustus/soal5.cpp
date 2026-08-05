#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cout << "Masukkan jumalh angka: " << endl;
    cin >> n;
    vector<int> arr;

    for(int i = 0; i<n; i++){
        cout << "masukkan angka ke-" << i+1 << ": " << endl;
        int x;
        cin >> x;
        arr.push_back(x);
    }

    long long tot = 1;
    for(int i = 0; i < n; i++){
        tot = (long long)tot * arr[i];
    }
    cout << "Hasil kali: " << tot << endl;
    sort(arr.begin(), arr.end());

        cout << "array teruntut: ";
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
        cout << endl;

}