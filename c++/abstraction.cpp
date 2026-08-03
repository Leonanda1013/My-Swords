#include <iostream>

using namespace std;


class abstractionEmployee{ //ini abstrac agar orang lihat mudah apa saja yang harus ada di employee
    virtual void askPromotion() = 0; //pure virtual function, it is a function that has no implementation and must be implemented by the derived class
};

class Employee : abstractionEmployee{ // ini adalah class turunan dari class abstractionEmployee, sehingga harus mengimplementasikan fungsi askPromotion
public:
    string Name;
    int Age;

    void askPromotion(){ // ini kode rummit yang tidak dilihat orang, tapi orang bisa lihat apa saja yang harus ada di employee
        if(Age > 30){
            cout << Name << " got promoted!" << endl;
        }else{
            cout << Name << " sorry no promotion for you!" << endl;
        }
    }
};
int main(){
    Employee emp1;
    emp1.Name = "John";
    emp1.Age = 35;
    emp1.askPromotion(); // calling the method askPromotion of emp1 object

    Employee emp2;
    emp2.Name = "Doe";
    emp2.Age = 25;
    emp2.askPromotion();
    return 0;
};