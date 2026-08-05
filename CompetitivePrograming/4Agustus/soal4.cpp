#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr;
    cout << "Masukkan jumlah angka: " << endl;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "Masukkan angka ke-" << i+1 << ": " << endl;
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());
    cout << "Array setelah diurutkan: ";
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}