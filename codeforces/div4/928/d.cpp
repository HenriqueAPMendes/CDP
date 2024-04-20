#include <bits/stdc++.h>
using namespace std;

#define int long long int 
#define endl '\n'
#define vi vector<int>

void solve(){
    int n; cin >> n;
    vector<vi> freq(31, vi(2));
    map<int,int> cnt;
    while(n--){
        int x; cin >> x;
        int notX = (~x)^(1<<31);
        cnt[x]++;
        // cnt[notX]++;
    }
    int ans = 0;
    for (auto &[x,cntX] : cnt){
        if (cntX == 0) continue;
        int notX = (~x)^(1<<31);
        int &cntNotX = cnt[notX];
        // cout << x << ' ' << cntX << " || " << notX << ' ' << cntNotX << endl;
        // cout << "max" << max(cntX, cntNotX) << endl;
        ans += max(cntX, cntNotX);
        cnt[notX] -= cntX;
        cntX -= cntNotX;
        if (cntX < 0) cntX = 0;
        if (cnt[notX] < 0) cnt[notX] = 0;
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