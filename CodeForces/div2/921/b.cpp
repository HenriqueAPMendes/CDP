#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define endl '\n'
#define vii vector<ii>

void solve(){
    int x, n, ans = 1;
    cin >> x >> n;
    for(int d = 1; d*d <= x; d++){
        if (x%d) continue;
        if (n*d <= x) ans = max(ans, d);
        if (n <= d) ans = max(ans, x/d); // WHY?
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}