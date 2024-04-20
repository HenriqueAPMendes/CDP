#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define iii pair<int,ii>
#define endl '\n'

void solve(){
    int n; cin >> n;
    vi a(n);
    int sum = 0;

    for (int i = 0; i < n; i++) { cin >> a[i]; sum += a[i]; }
    int meta = sum/n;
    int diff = 0;
    for (int i = n-1; i >= 0; i--){
        diff += a[i] - meta;
        if (diff > 0){ cout << "NO" << endl; return; }
    }
    cout << "YES" << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}