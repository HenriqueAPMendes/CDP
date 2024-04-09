#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vii v(n);
    for (int i = 0; i < n; i++) 
        cin >> v[i].second >> v[i].first;
    sort(v.begin(), v.end());
    int ans = 0, lastending = 0;
    for (int i = 0; i < n; i++){
        // cout << v[i].second << ' ' << v[i].first << endl;
        if (v[i].second >= lastending) {ans++; lastending = v[i].first;}
    }
    cout << ans << endl;

    return 0;
}