#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// soma de prefixos ou two pointers
// CURSO TWO POINTERS CODEFORCES

int main(){
    cin.tie(0);    
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    int parity = 0;

    ll odd_gap = 0;
    ll q = 0;

    for (int r = 0; r < n; r++){
        int b; cin >> b;
        if (b == 1) parity ^= 1;
        if (parity){
            q += r+1-odd_gap;
            odd_gap++;
        } else {
            q += odd_gap;
        }
    }

    cout << q << endl;

    return 0;
}