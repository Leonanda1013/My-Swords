#include <bits/stdc++.h>
using namespace std;

void gandakan(vector<int>&arr){
    for(int i=0; i<arr.size(); i++){
        arr[i] *= 2;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
    cout << "Sebelum digandakan: ";
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    gandakan(arr);

    cout << "Setelah digandakan: ";
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;

}