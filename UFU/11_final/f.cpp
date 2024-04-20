#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

vector<ii> bits(256);

void solve(){
    int comp; cin >> comp;
    int p; cin >> p;
    vi v(p);
    for (int i = 0; i < p; i++) cin >> v[i];

    if (comp == 8){
        for (auto x : v) cout << x << ' ';
        cout << endl;
        return;
    }
    for (auto x : v) cout << bits[x].first << ' ' << bits[x].second << ' ';
    cout << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 0; i < 256; i++){
        vi bitstring(8);
        if (i & (1 << 7)) bitstring[7] = 1;
        if (i & (1 << 6)) bitstring[6] = 1;
        if (i & (1 << 5)) bitstring[5] = 1;
        if (i & (1 << 4)) bitstring[4] = 1;
        if (i & (1 << 3)) bitstring[3] = 1;
        if (i & (1 << 2)) bitstring[2] = 1;
        if (i & (1 << 1)) bitstring[1] = 1;
        if (i & (1 << 0)) bitstring[0] = 1;
        // definir string 8bits
        int msb = (bitstring[7] << 3) + (bitstring[6] << 2) + (bitstring[5] << 1) + (bitstring[4] << 0);
        int lsb = (bitstring[3] << 3) + (bitstring[2] << 2) + (bitstring[1] << 1) + (bitstring[0] << 0);
        bits[i] = {msb,lsb};
    }

    // cout << "calculated" << endl;
    int t; cin >> t;
    while(t--) solve();

    return 0;
}