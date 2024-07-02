#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define vvi vector<vi>

void solve(){
    int n; cin >> n;
    vi a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while(!(a[i]&1)) a[i] /= 2, ans++;
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}