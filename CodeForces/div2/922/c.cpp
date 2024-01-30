#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>

void solve(){
    int a, b, r;
    cin >> a >> b >> r;

    // get max bit
    if (r == 0){ cout << abs(a-b) << endl; return; }
    int maxbit = (int)log2(r);
    int x = 0;

    for (int i = maxbit; i >= 0; i--){
        int x1 = x | (1<<i);
        int op1 = (a^x) - (b^x); // como fica mantendo bit = 0
        int op2 = (a^x1) - (b^x1); // como fica alterando bit para 1
        // cout << x << ' ' << x1 << endl;
        if (abs(op1) > abs(op2)) x = x1;
    }   

    int ans = abs((a^x) - (b^x));
    cout << endl << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();    

    return 0;
}