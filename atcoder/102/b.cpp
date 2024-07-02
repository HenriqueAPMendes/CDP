#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define vvi vector<vi>

void solve(){
    int n; cin >> n;
    int mn = 1e10, mx = 0;
    while(n--){
        int x; cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    cout << mx-mn << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}