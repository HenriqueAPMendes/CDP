#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define iii pair<int,ii>
#define endl '\n'

void solve(){
    int n, x, y, aux;
    cin >> n >> x >> y;
    
    vector<iii> a(n);
    map<ii,int> freq; // frequencia de pares {%x, %y}

    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = {a[i].first%x, a[i].first%y};
        freq[a[i].second]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ii target = {x - a[i].first%x, a[i].first%y};
        if (a[i].first%x == 0) target.first = 0;
        if (freq.count(target)) {
            ans += freq[target];
            if (a[i].second == target) ans--;
            // cout << target.first << ' ' << target.second << endl;
        }
    }
    cout << ans/2 << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}