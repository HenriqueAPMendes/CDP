#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

void solve(){
    int T, d, m;
    cin >> T >> d >> m;
    vi ref(m);
    bool can = false;
    int lastTime = 0;
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        if (t - lastTime >= T) can = true;
        lastTime = t;
    }
    if (d - lastTime >= T) can = true;

    cout << (can ? 'Y' : 'N') << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}