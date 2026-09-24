#include <iostream>
using namespace std;

int kuadrat(int n){
    n = n*n;
    cout << n << endl;
    return 0;
}

bool isGenap(int n){
    if (n % 2 == 0)
    {
        cout << "true" << endl;
        return true;
        
    } else {
        cout << "false" << endl;
        return false;
    }
    
}

void cetakGaris(int panjang){
    for (int i = 0; i < panjang; i++)
    {
        cout << "---" << "";
    }
      
}
int main(){
    kuadrat(10);
    isGenap(11);
    cetakGaris(5);
}