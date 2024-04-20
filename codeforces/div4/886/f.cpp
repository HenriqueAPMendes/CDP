#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>

void solve(){
    int n; cin >> n;
    vi a(n+1);
    vi cnt(n+1);

    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x <= n) cnt[x]++;
    }
    
    for (int i = 1; i <= n; i++){
        if (cnt[i] == 0) continue;
        for (int j = i; j <= n; j+=i)
            a[j]+=cnt[i];
    }

    cout << *max_element(a.begin(), a.end()) << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}