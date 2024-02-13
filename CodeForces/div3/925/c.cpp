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
    for (int i = 0; i < n; i++) cin >> a[i];

    // maior prefixo e maior sufixo
    int prefix = 1;
    int first = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] == first) prefix++; 
        else break;
    }

    int sufix = 1;
    int last = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        if (a[i] == last) sufix++; 
        else break;
    }

    // cout << prefix << ' ' << first << " -- " << sufix << ' ' << last << endl;

    int ans1 = n-prefix;
    int ans2 = n-sufix;
    int ans3 = max(n-prefix-sufix,(long long)0);

    if(first == last) cout << min(ans1, min(ans2, ans3)) << endl;
    else cout << min(ans1, ans2) << endl;

}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}