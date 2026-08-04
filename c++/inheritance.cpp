#include <iostream>

using namespace std;

class Mobil{
    public:
        string Merk;

        void jalan(){
            cout<< "Mobil " << Merk << " sedang berjalan" << endl;
        }

        Mobil(string m){
            Merk = m;
        }
};

class MobilListrik : public Mobil{
    public:
        int Baterai;

        void isiBaterai(){
            cout<< "Mobil " << Merk << " sedang diisi baterai" << endl;
        }

        MobilListrik(string m, int b) : Mobil(m){
            Baterai = b;
        }
};

int main(){
    Mobil mobil1("toyota");
    mobil1.jalan();

    MobilListrik mobil_listrik1("tesla", 100);
    mobil_listrik1.jalan();
    mobil_listrik1.isiBaterai();

}