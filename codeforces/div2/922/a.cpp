#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>

void solve(){
    int n, m;
    cin >> n >> m;

    int ans = 0;

    ans = m>>1;
    ans *= n;

    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}