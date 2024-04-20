#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>

void printv(vi v){
    for (auto x : v) cout << x << ' ';
    cout << endl;
}

void solve(){
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // cout << "START\n";
    // printv(a);

    bool valid = true;
    for (int i = 1; i < n-1; i++){
        a[i+1] -= a[i-1];
        a[i] -= 2*a[i-1];
        a[i-1] = 0;
        if (a[i] < 0 || a[i+1] < 0) {valid = false; break;}
        // printv(a);
    }

    if (a[n-2] != 0 || a[n-1] != 0) valid = false;
    
    cout << (valid ? "YES" : "NO") << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; 
    cin >> t;
    while(t--) solve();

    return 0;
}