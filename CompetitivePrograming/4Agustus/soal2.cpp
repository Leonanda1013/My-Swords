#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // vector<long long> n;
    // n.push_back(1);
    // n.push_back(2);
    // n.push_back(3);
    // n.push_back(4);
    // n.push_back(5);
    // long long tot = 0;
    // for(int i=0; i<n.size(); i++){
    //     tot += n[i];
    // }
    // cout << tot << endl;

    // pembetulan
    int n;
    cin >> n;

    vector<long long> arr;
    for(int i=0; i<n; i++){
        long long x;
        cin >> x;
        arr.push_back(x);
    }

    long long tot = 0;
    for(int i=0; i<arr.size(); i++){
        tot += arr[i];
    }
    cout << tot << endl;
    return 0;
}