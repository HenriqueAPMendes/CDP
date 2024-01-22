#include <bits/stdc++.h>
using namespace std;

int main(){

    int cntD = 0, cntE = 0;

    __int128_t n;

    int t; cin >> t;
    while(t--){
        int x;
        char c;
        cin >> x >> c;
        if (c == 'D') cntD+=x;
        else cntE+=x;
    }
    cout << min(cntE,cntD) << endl;
}