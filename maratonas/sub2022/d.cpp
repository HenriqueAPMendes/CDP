#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define vii vector<ii>
#define vvii vector<vii>

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    // testar divisibilidades
    int ans = 0;
    while(true){
        if (x % (1 << (n-ans)) == 0) break;
        else ans++;
    }
    cout << ans-1 << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}