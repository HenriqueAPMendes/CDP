#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = a;
    if (b%3 == 0){
        ans += b/3;
        ans += c/3;
        if (c%3) ans++;
    }
    else if (c >= 3 - b%3){
        ans += (b+c)/3;
        if ((b+c)%3) ans++;
    }
    else ans = -1;
    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}