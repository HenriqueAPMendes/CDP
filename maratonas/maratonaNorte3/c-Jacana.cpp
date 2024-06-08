#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

void solve(){
    int p, c, n;
    cin >> p >> c >> n;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int wei = p+c;
    int ans = 0;
    if (v[0] < p) { cout << 0 << endl; return; }
    wei = min(wei, v[0]);
    for (int i = 1; i < n; i++){
        if (v[i] < p) break;
        if (v[i] < wei){
            ans++;
            wei = v[i];
        }
    }

    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}