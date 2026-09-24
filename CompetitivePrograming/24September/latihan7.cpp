#include <iostream>
#include <vector>
using namespace std;

int cariMax(vector<int>&arr, int jmlElemen){
    int nilaiMax = arr[0]; 
    for (int i = 0; i < jmlElemen; i++)
     {
        if (nilaiMax < arr[i]){
            nilaiMax = arr[i];
        }
         
     }
     return nilaiMax;
}
int main(){
    int jmlElemen;
    cout << "Masukkan jumlah elemen" << endl;
    cin >> jmlElemen;

    vector<int> nilai;
    int inputNilai;

    for (int i = 0; i < jmlElemen; i++)
    {
        cout << "Masukkan nilai ke-" << i << endl;
        cin >> inputNilai;
        nilai.push_back(inputNilai);
    }
    int hasil = cariMax(nilai, jmlElemen);
    cout << "nilai max" <<hasil << endl;
    
}
