#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

void solve(){
    int a1, a2, a3, a4, a5;
    cin >> a1;
    cin >> a2;
    cin >> a3;
    cin >> a4;
    cin >> a5;
    int ans = 225 + a1*300 + a2*1500 + a3*600 + a4*1000 + a5*150;
    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}