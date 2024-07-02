#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define vvi vector<vi>

void solve(){
    int d, n;
    cin >> d >> n;
    int ans = n;
    if (ans == 100) ans++;
    if (d == 1) ans *= 100;
    if (d == 2) ans *= 10000;
    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}