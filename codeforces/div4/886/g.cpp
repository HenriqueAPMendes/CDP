#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>

void solve(){
    int n; cin >> n;
    map<int,int> row, col, rd, ld;

    while(n--){
        int x, y;
        cin >> x >> y;
        row[y]++;
        col[x]++;
        ld[x-y]++;
        rd[x+y]++;
    }
    int ans = 0;
    for (auto &[r, v] : row) ans += v*(v-1);
    for (auto &[c, v] : col) ans += v*(v-1);
    for (auto &[d, v] : rd) ans += v*(v-1);
    for (auto &[d, v] : ld) ans += v*(v-1);

    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}