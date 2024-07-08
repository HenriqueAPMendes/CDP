#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

void solve(){
    int n, l;
    cin >> n >> l;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.rbegin(), a.rend());
    int ans = 0;
    for (int i = 0; i < n; i++){
        int diff = 100 - a[i];
        if (l >= diff){
            l -= diff;
            ans ++;
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