#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<ii>
#define ii pair<int,int>

void solve(){
    int q, n, t;
    cin >> q >> n >> t;
    vii dt(q);
    for (int i = 0; i < q; i++)
        cin >> dt[i].first >> dt[i].second;
    
    sort (dt.begin(), dt.end());
    int limiteprava = 0;
    vi presum(q);
    presum[0] = dt[0].second;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}