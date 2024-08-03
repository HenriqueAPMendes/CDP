#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n; cin >> n;
    if (n & 1) cout << "Either" << endl;
    else cout << ((n%4) ? "Odd" : "Even") << endl;
}

int main(){
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}