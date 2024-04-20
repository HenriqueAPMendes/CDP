#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

void solve(){
    int a, b, m;
    cin >> a >> b >> m;
    m++;
    int ans = 0;
    ans += m/a;
    ans += m/b;
    if (m%a) ans++;
    if (m%b) ans++;
    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}