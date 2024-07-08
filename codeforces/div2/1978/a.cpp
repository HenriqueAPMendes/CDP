#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'

void solve(){
    int n; cin >> n;
    int maxelem = 0, x;
    for (int i = 0; i < n-1; i++) {
        cin >> x;
        maxelem = max(x, maxelem);
    }
    cin >> x;
    cout << x+maxelem << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}