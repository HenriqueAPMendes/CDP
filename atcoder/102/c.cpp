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
    for (int i = 0; i < n; i++){
        cin >> a[i]; a[i] -= (i+1);
    }
    sort(a.begin(), a.end());
    int b;
    if (n&1) b = a[n/2];
    else b = (a[n/2] + a[n/2 - 1])/2;

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(a[i]-b);
    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}