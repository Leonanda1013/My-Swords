#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a = -1, b = -1;

    while (a != 0 && a != 1){
        cin >> a;
    }
    while (b != 0 && b != 1){
        cin >> b;
    }

    cout << "AND=" << (a && b) << " OR=" << (a || b) << " XOR=" << (a ^ b) << endl;

    return 0;
}