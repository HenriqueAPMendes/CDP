#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

void solve(){
    int n, m;
    cin >> n >> m;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int ans = 0;
    for (int i = m; i < n; i++)
        ans += min(a[i], b[i]);

    int bestpos = a[m-1];
    int bsum = 0;
    for (int i = m-1; i >= 0; i--){
        int sum = a[i] + bsum;
        bestpos = min(bestpos, sum);
        bsum += min(a[i], b[i]);
    }

    ans += bestpos;
    
    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}