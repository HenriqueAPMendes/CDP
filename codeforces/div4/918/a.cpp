#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t,a,b,c;

    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        if (a == b) cout << c << endl;
        if (a == c) cout << b << endl;
        if (c == b) cout << a << endl;
    }

    return 0;
}