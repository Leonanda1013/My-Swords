#include <iostream>
using namespace std;

int main(){
    string nama;
    int umur;

    cout << "Nama : " ;
    cin >> nama;
    cout << "umur : ";
    cin >> umur;

    cout << "Halo " << nama << ", umur kamu "<< umur << " tahun" << endl;

    int a, b;
    cout << "Angka :";
    cin >> a >> b;
    int hasil = a + b;

    cout << "hasil a + b = " << hasil ;
    return 0;
}