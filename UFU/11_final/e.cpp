#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

vector<ii> bits(256);

void solve(){
    string s; cin >> s;
    string p1 = s.substr(0, 8);
    string p2 = s.substr(8, 8);
    string p3 = s.substr(16, 8);
    string p4 = s.substr(24, 8);
    int t1, t2, t3, t4;
    t1 = t2 = t3 = t4 = 0;
    for (int i = 0; i < 8; i++){
        t1 |= ((p1[7-i] - '0') << i);
        t2 |= ((p2[7-i] - '0') << i);
        t3 |= ((p3[7-i] - '0') << i);
        t4 |= ((p4[7-i] - '0') << i);
    
    }
    cout << t1 << '.' << t2 << '.' << t3 << '.' << t4 << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
