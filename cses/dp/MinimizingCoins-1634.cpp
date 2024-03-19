#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'
#define INF 1234567890

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, x;
    cin >> n >> x;

    vi coin(n);
    for (int i = 0; i < n; i++) cin >> coin[i];

    vi dp(x+1, INF);
    dp[0] = 0;
    for (int i = 1; i <= x; i++){
        for (auto c : coin){
            if (i - c >= 0) dp[i] = min(dp[i], dp[i-c]+1);
        }
    }

    if (dp[x] == INF) cout << -1 << endl;
    else cout << dp[x] << endl;

    return 0;
}