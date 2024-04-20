#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ii pair<int,int>
#define endl '\n'
#define vi vector<int>

void solve(){
    int n; cin >> n;
    vi signs(n);
    for (int i = 0; i < n; i++) cin >> signs[i];
    int ans = signs[0];
    for (int i = 1; i < n; i++){
        ans += (signs[i]-ans%signs[i]);
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